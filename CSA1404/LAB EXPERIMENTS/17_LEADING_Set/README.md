# Experiment 17: LEADING() Set Computation for Operator Precedence Grammar

## Aim
Compute `LEADING()` sets in C for the operator precedence grammar `E -> E+T | T`, `T -> T*F | F`, `F -> (E) | id`.

## Algorithm
1. Encode the exact grammar rules `E -> E+T | T`, `T -> T*F | F`, `F -> (E) | id`.
2. For each rule `A -> a...` or `A -> B a...`, add terminal `a` directly to `LEADING(A)`.
3. Propagate all symbols in `LEADING(B)` to `LEADING(A)` for rules starting with non-terminal `B` until convergence.
4. Print `LEADING(E)`, `LEADING(T)`, and `LEADING(F)`.

## Source Files
- `main.c`: Source implementation.

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
```

## Execution
```bash
./main
```

## Sample Input
No external input file required; grammar is embedded directly as specified.

## Output
```text
====================================================
   LEADING() SET - OPERATOR PRECEDENCE PARSER       
====================================================
Grammar:
  E -> E + T | T
  T -> T * F | F
  F -> ( E ) | id
----------------------------------------------------
LEADING(E) = { +, *, (, id }
LEADING(T) = { *, (, id }
LEADING(F) = { (, id }
----------------------------------------------------
```

## Result
The program computed exact operator-precedence `LEADING()` sets for `E`, `T`, and `F`.
