# Experiment 08: FOLLOW() Set Computation for Predictive Parser

## Aim
Implement a C program to compute the `FOLLOW()` sets for the predictive parser grammar `S -> AaAb | BbBa`, `A -> eps`, `B -> eps`.

## Algorithm
1. Initialize `FOLLOW(S)` with the end-of-input marker `$`.
2. Compute `FIRST()` sets for all grammar symbols as prerequisites.
3. For every production `X -> alpha B beta`, add `FIRST(beta) - {eps}` to `FOLLOW(B)`; if `beta` can derive epsilon or is empty, add `FOLLOW(X)` to `FOLLOW(B)`.
4. Iterate until no new symbols are added and display `FOLLOW(S)`, `FOLLOW(A)`, and `FOLLOW(B)`.

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
     FOLLOW() SET COMPUTATION - PREDICTIVE PARSER   
====================================================
Given Grammar (eps denotes epsilon):
  S -> AaAb / BbBa
  A -> eps
  B -> eps
----------------------------------------------------
FOLLOW(S) = { $ }
FOLLOW(A) = { a, b }
FOLLOW(B) = { b, a }
----------------------------------------------------
```

## Result
The program accurately computed `FOLLOW(S) = { $ }`, `FOLLOW(A) = { a, b }`, and `FOLLOW(B) = { a, b }`.
