# Experiment 07: FIRST() Set Computation for Predictive Parser

## Aim
Implement a C program to compute the `FIRST()` sets for the predictive parser grammar `S -> AaAb | BbBa`, `A -> eps`, `B -> eps`.

## Algorithm
1. Represent the exact CFG productions (`S -> AaAb / BbBa`, `A -> eps`, `B -> eps`) in memory.
2. For each symbol `X`, if `X` is terminal, `FIRST(X) = { X }`.
3. If `X` is non-terminal, examine each production `X -> Y1 Y2 ... Yk` and add non-epsilon symbols from `FIRST(Yi)` until an `Yi` does not derive epsilon.
4. Add epsilon to `FIRST(X)` if `X -> eps` or every `Yi` derives epsilon, then print `FIRST(S)`, `FIRST(A)`, and `FIRST(B)`.

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
      FIRST() SET COMPUTATION - PREDICTIVE PARSER   
====================================================
Given Grammar (eps denotes epsilon):
  S -> AaAb / BbBa
  A -> eps
  B -> eps
----------------------------------------------------
FIRST(S) = { a, b }
FIRST(A) = { eps }
FIRST(B) = { eps }
----------------------------------------------------
```

## Result
The program correctly computed `FIRST(S) = { a, b }`, `FIRST(A) = { eps }`, and `FIRST(B) = { eps }` matching the predictive parser grammar.
