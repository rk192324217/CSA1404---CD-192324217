# CSA14 - Compiler Design Laboratory (40 Experiments)

## Project Overview
- **Project Title**: Compiler Design Laboratory Experiments (CSA14 / CSA1404)
- **Institution**: Saveetha School of Engineering (SIMATS) — Institute of CSE
- **Subject**: CSA14 - Compiler Design
- **Total Number of Experiments**: 40 (Organized across 4 Batches of 10 experiments each)
- **Overall Completion Status**: **40 / 40 Completed** (Compiled, Executed, Verified, Documented, and Terminal Screenshots Captured)

---

## Linux Execution Environment Details
All C and LEX/FLEX programs were compiled and executed inside **WSL2 Ubuntu Linux**:
- **Operating System / Kernel**: `Ubuntu Linux (WSL2) — Linux 6.18.33.2-microsoft-standard-WSL2 x86_64`
- **GCC Version**: `gcc (Ubuntu 15.2.0-16ubuntu1) 15.2.0`
- **FLEX Version**: `flex 2.6.4`
- **Bison Version**: `bison (GNU Bison) 3.8.2`
- **Terminal Capture Toolchain**: `xterm` (DejaVu Sans Mono) inside headless X11 (`Xvfb`), `scrot`, and `ImageMagick`

---

## Installation Instructions (Ubuntu / WSL2)
```bash
sudo apt update
sudo apt install -y flex bison gcc build-essential make libfl-dev
gcc --version
flex --version
bison --version
```

---

## Compilation & Execution Instructions

### C Programs (`.c`)
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
./main [sample_input_file]
```

### LEX / FLEX Programs (`.l`)
```bash
flex main.l
gcc -std=c11 -Wall -Wextra -O2 lex.yy.c -o main -lfl
./main [sample_input_file]
```

---

## Project Folder Structure
```text
LAB EXPERIMENTS/
├── README.md
├── Batch01/   (Experiments 01 – 10)
├── Batch02/   (Experiments 11 – 20)
├── Batch03/   (Experiments 21 – 30)
└── Batch04/   (Experiments 31 – 40)
```
Each experiment folder contains:
- Source implementation (`main.c` or `main.l`)
- Required sample input file (`sample_input.c`, `sample_input.txt`, `sample.c`, `input.c`, or `sample.html`)
- `execution_output.txt` (actual stdout output)
- `execution_screenshot.png` (genuine Linux `xterm` terminal screenshot)
- `README.md` (Aim, Algorithm, Source Files, Compilation, Execution, Input, Output, Result)

---

## Batch-Wise Experiment Tracker

### Batch 01 (Experiments 01 – 10)

| Experiment | Name | Source | Compiled | Executed | Screenshot |
|---|---|---|---|---|---|
| 01 | [Lexical Analyzer (Identifiers, Constants, Operators)](Batch01/01_Lexical_Analyzer/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch01/01_Lexical_Analyzer/execution_screenshot.png) |
| 02 | [Comment Recognition (`//` and `/* ... */`)](Batch01/02_Comment_Recognition/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch01/02_Comment_Recognition/execution_screenshot.png) |
| 03 | [Ignore Redundant Spaces, Tabs, Newlines & Comments](Batch01/03_Redundant_Spaces_Comments/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch01/03_Redundant_Spaces_Comments/execution_screenshot.png) |
| 04 | [Arithmetic Operator Validation (`+`, `-`, `*`, `/`)](Batch01/04_Operator_Validation/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch01/04_Operator_Validation/execution_screenshot.png) |
| 05 | [Whitespace and Newline Character Counter](Batch01/05_Whitespace_Newline_Counter/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch01/05_Whitespace_Newline_Counter/execution_screenshot.png) |
| 06 | [Identifier Validation](Batch01/06_Identifier_Validation/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch01/06_Identifier_Validation/execution_screenshot.png) |
| 07 | [Predictive Parser `FIRST()` Set Computation](Batch01/07_FIRST_Set/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch01/07_FIRST_Set/execution_screenshot.png) |
| 08 | [Predictive Parser `FOLLOW()` Set Computation](Batch01/08_FOLLOW_Set/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch01/08_FOLLOW_Set/execution_screenshot.png) |
| 09 | [Elimination of Left Recursion from CFG](Batch01/09_Left_Recursion/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch01/09_Left_Recursion/execution_screenshot.png) |
| 10 | [Elimination of Left Factoring from CFG](Batch01/10_Left_Factoring/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch01/10_Left_Factoring/execution_screenshot.png) |

---

### Batch 02 (Experiments 11 – 20)

| Experiment | Name | Source | Compiled | Executed | Screenshot |
|---|---|---|---|---|---|
| 11 | [Symbol Table Operations](Batch02/11_Symbol_Table_Operations/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/11_Symbol_Table_Operations/execution_screenshot.png) |
| 12 | [Recursive Descent Parsing](Batch02/12_Recursive_Descent_Parsing/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/12_Recursive_Descent_Parsing/execution_screenshot.png) |
| 13 | [Bottom-Up Shift-Reduce Parsing (Grammar Check)](Batch02/13_Grammar_String_Validation/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/13_Grammar_String_Validation/execution_screenshot.png) |
| 14 | [Three Address Code (TAC) Generation](Batch02/14_Three_Address_Code/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/14_Three_Address_Code/execution_screenshot.png) |
| 15 | [File Character, Word, and Line Counter](Batch02/15_File_Char_Word_Line_Counter/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/15_File_Char_Word_Line_Counter/execution_screenshot.png) |
| 16 | [Compiler Back End Implementation](Batch02/16_Compiler_Backend/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/16_Compiler_Backend/execution_screenshot.png) |
| 17 | [`LEADING()` Set Computation (Operator Precedence)](Batch02/17_LEADING_Set/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/17_LEADING_Set/execution_screenshot.png) |
| 18 | [`TRAILING()` Set Computation (Operator Precedence)](Batch02/18_TRAILING_Set/README.md) | `main.c` | Completed | Completed | [Screenshot](Batch02/18_TRAILING_Set/execution_screenshot.png) |
| 19 | [LEX C Source Counter (Ignoring Spaces & Comments)](Batch02/19_LEX_C_File_Counter/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch02/19_LEX_C_File_Counter/execution_screenshot.png) |
| 20 | [LEX Constants, Macros & Header Files Identifier](Batch02/20_LEX_Constants_Macros_Headers/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch02/20_LEX_Constants_Macros_Headers/execution_screenshot.png) |

---

### Batch 03 (Experiments 21 – 30)

| Experiment | Name | Source | Compiled | Executed | Screenshot |
|---|---|---|---|---|---|
| 21 | [Count Vowels in a Sentence](Batch03/21_Count_Vowels/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/21_Count_Vowels/execution_screenshot.png) |
| 22 | [Extract and Print HTML Tags](Batch03/22_HTML_Tag_Printer/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/22_HTML_Tag_Printer/execution_screenshot.png) |
| 23 | [Add Line Numbers to a C Source File](Batch03/23_Add_Line_Numbers/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/23_Add_Line_Numbers/execution_screenshot.png) |
| 24 | [Count and Eliminate Comments from a C File](Batch03/24_Count_Eliminate_Comments/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/24_Count_Eliminate_Comments/execution_screenshot.png) |
| 25 | [Identify Capital Words](Batch03/25_Capital_Words/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/25_Capital_Words/execution_screenshot.png) |
| 26 | [Email Address Validation](Batch03/26_Email_Validation/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/26_Email_Validation/execution_screenshot.png) |
| 27 | [Convert Substring `abc` to `ABC`](Batch03/27_Convert_abc_to_ABC/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/27_Convert_abc_to_ABC/execution_screenshot.png) |
| 28 | [Mobile Number Validation](Batch03/28_Mobile_Number_Validation/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/28_Mobile_Number_Validation/execution_screenshot.png) |
| 29 | [LEX Token Separator for C Program](Batch03/29_LEX_Token_Separator/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/29_LEX_Token_Separator/execution_screenshot.png) |
| 30 | [Count Consonants in a Sentence](Batch03/30_Count_Consonants/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch03/30_Count_Consonants/execution_screenshot.png) |

---

### Batch 04 (Experiments 31 – 40)

| Experiment | Name | Source | Compiled | Executed | Screenshot |
|---|---|---|---|---|---|
| 31 | [Separate Keywords and Identifiers](Batch04/31_Keywords_and_Identifiers/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/31_Keywords_and_Identifiers/execution_screenshot.png) |
| 32 | [Identify and Count Positive and Negative Numbers](Batch04/32_Positive_Negative_Numbers/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/32_Positive_Negative_Numbers/execution_screenshot.png) |
| 33 | [URL Validation](Batch04/33_URL_Validation/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/33_URL_Validation/execution_screenshot.png) |
| 34 | [Date of Birth (DOB) Validation](Batch04/34_DOB_Validation/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/34_DOB_Validation/execution_screenshot.png) |
| 35 | [Digit / Numeric Validation](Batch04/35_Digit_Validation/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/35_Digit_Validation/execution_screenshot.png) |
| 36 | [Basic Mathematical Operations](Batch04/36_Basic_Math_Operations/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/36_Basic_Math_Operations/execution_screenshot.png) |
| 37 | [Word Frequency Counter in a Sentence](Batch04/37_Word_Frequency_Counter/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/37_Word_Frequency_Counter/execution_screenshot.png) |
| 38 | [Find Length of the Longest Word](Batch04/38_Longest_Word_Length/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/38_Longest_Word_Length/execution_screenshot.png) |
| 39 | [Replace a Word with Another Word in a File](Batch04/39_Replace_Word_In_File/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/39_Replace_Word_In_File/execution_screenshot.png) |
| 40 | [FLEX Program for C Token Separation](Batch04/40_FLEX_C_Token_Separator/README.md) | `main.l` | Completed | Completed | [Screenshot](Batch04/40_FLEX_C_Token_Separator/execution_screenshot.png) |

