# Experiment 09: Elimination of Left Recursion from CFG

## Aim
Implement a C program to eliminate immediate left recursion from the grammar `S -> (L) / a`, `L -> L , S / S`.

## Algorithm
1. Load the CFG rules `S -> (L) | a` and `L -> L,S | S`.
2. Scan each non-terminal `A` for left-recursive alternatives of the form `A -> A alpha` and non-left-recursive alternatives `A -> beta`.
3. If left recursion exists, rewrite as `A -> beta A'` and `A' -> alpha A' | eps`.
4. Display the original CFG alongside the transformed left-recursion-free CFG.

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
        ELIMINATION OF LEFT RECURSION (CFG)         
====================================================
Original Grammar:
  S -> (L) | a
  L -> L,S | S
----------------------------------------------------
Grammar After Eliminating Left Recursion:
  S -> (L) | a
  L  -> SL'
  L' -> ,SL' | eps
----------------------------------------------------
```

## Result
Immediate left recursion on `L` was successfully eliminated, yielding `L -> SL'` and `L' -> ,SL' | eps`.
