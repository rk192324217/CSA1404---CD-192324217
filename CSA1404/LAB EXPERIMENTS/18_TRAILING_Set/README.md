# Experiment 18: TRAILING() Set Computation for Operator Precedence Grammar

## Aim
Compute `TRAILING()` sets in C for the operator precedence grammar `E -> E+T | T`, `T -> T*F | F`, `F -> (E) | id`.

## Algorithm
1. Encode the exact grammar rules `E -> E+T | T`, `T -> T*F | F`, `F -> (E) | id`.
2. For each rule ending in terminal `a` or `...a B`, add `a` directly to `TRAILING(A)`.
3. Propagate all symbols in `TRAILING(B)` to `TRAILING(A)` for rules ending in non-terminal `B` until convergence.
4. Print `TRAILING(E)`, `TRAILING(T)`, and `TRAILING(F)`.

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
   TRAILING() SET - OPERATOR PRECEDENCE PARSER      
====================================================
Grammar:
  E -> E + T | T
  T -> T * F | F
  F -> ( E ) | id
----------------------------------------------------
TRAILING(E) = { +, *, ), id }
TRAILING(T) = { *, ), id }
TRAILING(F) = { ), id }
----------------------------------------------------
```

## Result
The program computed exact operator-precedence `TRAILING()` sets for `E`, `T`, and `F`.
