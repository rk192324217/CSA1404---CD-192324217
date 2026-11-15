# Experiment 35: Check Whether Input is a Digit / Number

## Aim
Write a LEX program to test whether each input line is a valid digit/numeric value or not.

## Algorithm
1. Match integer or decimal numeric lines using `^[0-9]+(\.[0-9]+)?`.
2. Classify matches as `DIGIT / NUMERIC INPUT` and any alphabetic or symbolic lines as `NOT A DIGIT`.
3. Display totals of numeric vs non-digit inputs.

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
7
42
3.14
abc
12a
@
0
```

## Output
```text
====================================================
             DIGIT CHECKER (LEX PROGRAM)            
====================================================
7                  -> DIGIT / NUMERIC INPUT
42                 -> DIGIT / NUMERIC INPUT
3.14               -> DIGIT / NUMERIC INPUT
abc                -> NOT A DIGIT
12a                -> NOT A DIGIT
@                  -> NOT A DIGIT
0                  -> DIGIT / NUMERIC INPUT
----------------------------------------------------
Numeric/Digit Inputs: 4 | Non-Digit Inputs: 3
```

## Result
Numeric inputs were accurately recognized and non-digit inputs were rejected.
