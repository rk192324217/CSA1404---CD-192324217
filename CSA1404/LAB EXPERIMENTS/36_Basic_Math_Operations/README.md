# Experiment 36: Basic Mathematical Operations

## Aim
Implement a LEX program to recognize and evaluate basic arithmetic operations (`+`, `-`, `*`, `/`).

## Algorithm
1. Match binary arithmetic expressions `<operand1> <op> <operand2>`.
2. Extract operands and operator using `sscanf` and perform addition, subtraction, multiplication, or division (guarding against divide-by-zero).
3. Flag malformed expressions as `INVALID EXPRESSION`.

## Source Files
- `main.l`: Source implementation.
- `sample_input.txt`: Sample input file.

## Compilation
```bash
flex main.l
gcc -std=c11 -Wall -Wextra -O2 lex.yy.c -o main -lfl
```

## Execution
```bash
./main < sample_input.txt
```

## Sample Input
```
15 + 25
40 - 12
8 * 7
45 / 5
10 / 0
5 @ 3
```

## Output
```text
====================================================
      BASIC MATHEMATICAL OPERATIONS (LEX)           
====================================================
15 + 25            = 40.00 (Addition)
40 - 12            = 28.00 (Subtraction)
8 * 7              = 56.00 (Multiplication)
45 / 5             = 9.00 (Division)
10 / 0             -> ERROR: Division by zero
5 @ 3              -> INVALID EXPRESSION
----------------------------------------------------
```

## Result
All valid arithmetic expressions were evaluated accurately while division by zero and invalid operators were handled safely.
