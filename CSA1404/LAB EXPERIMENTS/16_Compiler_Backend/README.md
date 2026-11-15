# Experiment 16: Compiler Back End Implementation

## Aim
Implement the compiler back end in C to translate Three Address Code statements into target assembly instructions.

## Algorithm
1. Read three-address code instructions (`lhs = arg1 op arg2` or `lhs = arg1`) from the input file.
2. Map arithmetic operators (`+`, `-`, `*`, `/`) to target opcodes (`ADD`, `SUB`, `MUL`, `DIV`).
3. Allocate registers (`R0`–`R3`) cyclically and emit `MOV` and arithmetic assembly instructions.

## Source Files
- `main.c`: Source implementation.
- `sample_input.txt`: Sample input file.

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
```

## Execution
```bash
./main sample_input.txt
```

## Sample Input
```
t1 = b * c
t2 = a + t1
d = t2
```

## Output
```text
====================================================
       COMPILER BACK END (TARGET CODE GENERATOR)    
====================================================
Generating 8086/Register Assembly from Three-Address Code:
----------------------------------------------------
; TAC: t1 = b * c
  MOV R0, b
  MUL R0, c
  MOV t1, R0
; TAC: t2 = a + t1
  MOV R1, a
  ADD R1, t1
  MOV t2, R1
; TAC: d = t2
  MOV R2, t2
  MOV d, R2
----------------------------------------------------
```

## Result
The compiler backend successfully generated target register-based assembly code from three-address statements.
