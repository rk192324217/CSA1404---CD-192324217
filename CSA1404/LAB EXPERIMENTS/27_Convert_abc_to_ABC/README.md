# Experiment 27: Convert Substring 'abc' to 'ABC'

## Aim
Write a LEX program to replace every occurrence of the substring `abc` with `ABC` in the input text.

## Algorithm
1. Add a rule matching exact literal `"abc"` and emit `ABC` while incrementing the replacement counter.
2. Echo all other characters unchanged with `.|\n`.
3. Report total conversions performed.

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
hello abc world!
abctestabc123
compiler design abc lab
```

## Output
```text
====================================================
      CONVERT SUBSTRING 'abc' TO 'ABC' (LEX)        
====================================================
Converted Output:
hello ABC world!
ABCtestABC123
compiler design ABC lab
----------------------------------------------------
Total 'abc' -> 'ABC' conversions: 4
```

## Result
Every occurrence of `abc` was converted to `ABC` while leaving all surrounding characters intact.
