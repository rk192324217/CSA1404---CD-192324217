import os
import os
import sys
import time
import json
import subprocess
import shutil

BASE_WSL_PATH = "/mnt/v/RK/College/HS -2 2026/CSA1404 - CD 4/LAB EXPERIMENTS"

def run_single(batch_name, exp_folder_name, compile_cmd, exec_cmd, stdin_data=None, show_input_file=None, display=":99"):
    folder_wsl_path = f"{BASE_WSL_PATH}/{batch_name}/{exp_folder_name}"
    env = os.environ.copy()
    env["DISPLAY"] = display

    script_path = "/tmp/run_session.sh"
    ready_flag = "/tmp/session_ready"
    prog_out = "/tmp/prog_out.txt"
    status_file = "/tmp/prog_status.txt"

    for p in (ready_flag, prog_out, status_file):
        if os.path.exists(p):
            os.remove(p)

    stdin_heredoc = ""
    if stdin_data is not None:
        stdin_heredoc = f" << 'INPUT_EOF'\n{stdin_data}\nINPUT_EOF"

    full_exec_line = f"{exec_cmd}{stdin_heredoc}"

    # Optional command to display input file contents in terminal if helpful
    cat_input_block = ""
    if show_input_file:
        cat_input_block = f"""echo -e "${{PROMPT}}cat {show_input_file}"
cat "{show_input_file}"
echo ""
"""

    # If stdin_data is provided directly (without a file shown), echo it cleanly or show echo | ./main
    display_exec_cmd = exec_cmd
    if stdin_data is not None and not show_input_file and "<" not in exec_cmd:
        escaped_in = stdin_data.strip().replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n")
        display_exec_cmd = f'printf "{escaped_in}\\n" | {exec_cmd}'

    sh_script = f"""#!/bin/bash
cd "{folder_wsl_path}"
clear
PROMPT="\\033[01;32mrk@compiler-lab\\033[00m:\\033[01;34m~/LAB_EXPERIMENTS/{batch_name}/{exp_folder_name}\\033[00m\\$ "

{cat_input_block}echo -e "${{PROMPT}}{compile_cmd}"
{compile_cmd} > /tmp/comp_out.txt 2>&1
COMP_STATUS=$?
if [ -s /tmp/comp_out.txt ]; then
    cat /tmp/comp_out.txt
fi
if [ $COMP_STATUS -ne 0 ]; then
    echo "Compilation failed with exit code $COMP_STATUS"
    echo "COMPILE_FAIL:$COMP_STATUS" > "{status_file}"
    touch "{ready_flag}"
    sleep 5
    exit $COMP_STATUS
fi

echo -e "${{PROMPT}}{display_exec_cmd}"
{full_exec_line} > "{prog_out}" 2>&1
EXEC_STATUS=$?
cat "{prog_out}"
echo "OK:$EXEC_STATUS" > "{status_file}"

echo -ne "${{PROMPT}}"
touch "{ready_flag}"
sleep 10
"""
    with open(script_path, "w") as f:
        f.write(sh_script)
    os.chmod(script_path, 0o755)

    xterm = subprocess.Popen([
        "xterm",
        "-fa", "DejaVu Sans Mono",
        "-fs", "10",
        "-geometry", "110x50",
        "-bg", "#181818",
        "-fg", "#e6e6e6",
        "-title", f"rk@compiler-lab: ~/{batch_name}/{exp_folder_name}",
        "+sb",
        "-e", script_path
    ], env=env)

    # Wait for execution to finish
    for _ in range(100):
        if os.path.exists(ready_flag):
            time.sleep(0.45)
            break
        time.sleep(0.1)

    raw_png = f"/tmp/{exp_folder_name}.png"
    subprocess.run(["scrot", raw_png], env=env, capture_output=True)

    final_png = f"{folder_wsl_path}/execution_screenshot.png"
    out_txt = f"{folder_wsl_path}/execution_output.txt"

    if os.path.exists(raw_png) and os.path.getsize(raw_png) > 0:
        subprocess.run([
            "magick", raw_png,
            "-trim", "+repage",
            "-bordercolor", "#181818",
            "-border", "12x12",
            final_png
        ], capture_output=True)
        os.remove(raw_png)

    if os.path.exists(prog_out):
        shutil.copy(prog_out, out_txt)

    xterm.terminate()
    try:
        xterm.wait(timeout=2)
    except subprocess.TimeoutExpired:
        xterm.kill()

    # Clean up binary and generated lex/bison C files
    for temp_file in ("main", "lex.yy.c", "y.tab.c", "y.tab.h", "parser.tab.c", "parser.tab.h"):
        p = f"{folder_wsl_path}/{temp_file}"
        if os.path.exists(p):
            os.remove(p)

    status_str = ""
    if os.path.exists(status_file):
        with open(status_file, "r") as sf:
            status_str = sf.read().strip()

    comp_err = ""
    if os.path.exists("/tmp/comp_out.txt"):
        with open("/tmp/comp_out.txt", "r") as cf:
            comp_err = cf.read().strip()

    if not status_str.startswith("OK:0"):
        print(f"[FAIL] {exp_folder_name} -> status={status_str} | comp={comp_err}")
        return False

    if not os.path.exists(final_png) or os.path.getsize(final_png) == 0:
        print(f"[FAIL] {exp_folder_name} -> missing screenshot")
        return False

    if not os.path.exists(out_txt):
        print(f"[FAIL] {exp_folder_name} -> missing execution_output.txt")
        return False

    print(f"[PASS] {exp_folder_name} (warnings/comp: {'NONE' if not comp_err else comp_err})")
    return True

def main():
    display = ":99"
    check_xvfb = subprocess.run(["pgrep", "-f", f"Xvfb {display}"], capture_output=True, text=True)
    xvfb_proc = None
    if check_xvfb.returncode != 0:
        xvfb_proc = subprocess.Popen(["Xvfb", display, "-screen", "0", "1280x1024x24"],
                                     stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        time.sleep(0.8)

    all_ok = True
    try:
        if len(sys.argv) == 3 and sys.argv[1] == "--batch":
            with open(sys.argv[2], "r") as f:
                jobs = json.load(f)
            for job in jobs:
                ok = run_single(
                    job["batch"],
                    job["folder"],
                    job["compile_cmd"],
                    job["exec_cmd"],
                    job.get("stdin_data"),
                    job.get("show_input_file"),
                    display=display
                )
                if not ok:
                    all_ok = False
        elif len(sys.argv) >= 5:
            b_name = sys.argv[1]
            f_name = sys.argv[2]
            c_cmd = sys.argv[3]
            e_cmd = sys.argv[4]
            s_data = None
            if len(sys.argv) >= 6 and os.path.exists(sys.argv[5]):
                with open(sys.argv[5], "r") as f:
                    s_data = f.read()
            all_ok = run_single(b_name, f_name, c_cmd, e_cmd, s_data, display=display)
        else:
            print("Usage: python3 run_experiment.py <batch> <folder> <compile_cmd> <exec_cmd> [stdin_file]")
            print("   or: python3 run_experiment.py --batch <manifest.json>")
            sys.exit(1)
    finally:
        if xvfb_proc:
            xvfb_proc.terminate()

    sys.exit(0 if all_ok else 1)

if __name__ == "__main__":
    main()
