# Experiment 04: Arithmetic Operator Validation

## Aim
Design a LEX lexical analyzer to validate basic arithmetic operators (`+`, `-`, `*`, `/`).

## Algorithm
1. Define a regular expression matching exact single arithmetic operators `+`, `-`, `*`, `/`.
2. Print the operator name (`Addition`, `Subtraction`, `Multiplication`, `Division`) when valid.
3. Flag any other operator or symbol sequence as `INVALID ARITHMETIC OPERATOR`.
4. Track total valid and invalid operator counts.

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
+
-
*
/
%
++
=
@
```

## Output
```text
====================================================
       ARITHMETIC OPERATOR VALIDATOR (+,-,*,/)      
====================================================
+               -> VALID ARITHMETIC OPERATOR (Addition)
-               -> VALID ARITHMETIC OPERATOR (Subtraction)
*               -> VALID ARITHMETIC OPERATOR (Multiplication)
/               -> VALID ARITHMETIC OPERATOR (Division)
%               -> INVALID ARITHMETIC OPERATOR
++              -> INVALID ARITHMETIC OPERATOR
=               -> INVALID ARITHMETIC OPERATOR
@               -> INVALID ARITHMETIC OPERATOR
----------------------------------------------------
Valid operators: 4 | Invalid inputs: 4
```

## Result
The arithmetic operator validator compiled and accurately distinguished valid `+`, `-`, `*`, `/` operators from invalid symbols.
