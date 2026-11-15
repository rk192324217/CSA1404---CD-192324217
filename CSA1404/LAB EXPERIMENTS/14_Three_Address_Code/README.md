# Experiment 14: Three Address Code Generation

## Aim
Write a C program to generate Three Address Code (TAC) intermediate representation for arithmetic assignment statements.

## Algorithm
1. Split the statement into left-hand variable and right-hand expression.
2. Convert the right-hand infix expression into postfix form respecting operator precedence (`*`, `/` over `+`, `-`) and parentheses.
3. Evaluate the postfix string using an operand stack, emitting `t1, t2, ...` temporary assignments for each binary operator.
4. Emit the final assignment to the target LHS variable.

## Source Files
- `main.c`: Source implementation.
- `sample_input.txt`: Sample input file.

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
```

## Execution
```bash
./main < sample_input.txt
```

## Sample Input
```
a = b + c * d
x = (a + b) * (c - d) / e
```

## Output
```text
====================================================
      INTERMEDIATE CODE: THREE ADDRESS CODE (TAC)   
====================================================
Input Statement: a = b + c * d
Three Address Code:
  t1 = c * d
  t2 = b + t1
  a = t2
----------------------------------------------------
Input Statement: x = (a + b) * (c - d) / e
Three Address Code:
  t1 = a + b
  t2 = c - d
  t3 = t1 * t2
  t4 = t3 / e
  x = t4
----------------------------------------------------
```

## Result
The intermediate code generator produced accurate Three Address Code sequences for arithmetic expressions.
