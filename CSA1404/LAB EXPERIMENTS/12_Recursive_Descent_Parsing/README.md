# Experiment 12: Recursive Descent Parsing

## Aim
Construct a C recursive descent parser for the LL(1) expression grammar `E -> TE'`, `E' -> +TE'|eps`, `T -> FT'`, `T' -> *FT'|eps`, `F -> (E)|id`.

## Algorithm
1. Write one recursive function per non-terminal: `E()`, `Eprime()`, `T()`, `Tprime()`, and `F()`.
2. Match expected tokens (`+`, `*`, `(`, `)`, `id`) using a lookahead pointer `pos`.
3. Report `ACCEPTED` when parsing consumes the entire input string without error, or `REJECTED` otherwise.

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
id+id*id
(id+id)*id
id*id+id
id+*id
(id+id
```

## Output
```text
====================================================
        RECURSIVE DESCENT PARSER (LL(1))            
====================================================
Grammar:
  E  -> TE'       E' -> +TE' | eps
  T  -> FT'       T' -> *FT' | eps
  F  -> (E) | id
----------------------------------------------------
Input: id+id*id               -> ACCEPTED (Valid syntax)
Input: (id+id)*id             -> ACCEPTED (Valid syntax)
Input: id*id+id               -> ACCEPTED (Valid syntax)
Input: id+*id                 -> REJECTED (Syntax error at pos 3)
Input: (id+id                 -> REJECTED (Syntax error at pos 6)
----------------------------------------------------
```

## Result
The recursive descent parser accurately validated valid expressions and caught syntax errors in malformed inputs.
