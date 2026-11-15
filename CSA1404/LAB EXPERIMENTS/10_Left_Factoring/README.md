# Experiment 10: Elimination of Left Factoring from CFG

## Aim
Implement a C program to perform left factoring on the CFG `S -> iEtS / iEtSeS / a`, `E -> b`.

## Algorithm
1. Store the CFG rules `S -> iEtS | iEtSeS | a` and `E -> b`.
2. Compare pairs of alternatives for each non-terminal to determine the longest common prefix `alpha` (`iEtS`).
3. Factor out the common prefix into a new non-terminal `S'` producing remaining suffixes (`eps | eS`).
4. Output the original and left-factored grammars.

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
        ELIMINATION OF LEFT FACTORING (CFG)         
====================================================
Original Grammar:
  S -> iEtS | iEtSeS | a
  E -> b
----------------------------------------------------
Grammar After Left Factoring:
  S  -> iEtSS' | a
  S' -> eps | eS
  E  -> b
----------------------------------------------------
```

## Result
Left factoring succeeded, transforming `S` into `S -> iEtSS' | a` and `S' -> eps | eS`.
