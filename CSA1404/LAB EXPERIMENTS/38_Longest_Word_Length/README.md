# Experiment 38: Find Length of the Longest Word

## Aim
Write a LEX program to determine the longest alphabetic word and its length in an input text.

## Algorithm
1. Match each alphabetic word using `[a-zA-Z]+`.
2. Compare `yyleng` against `max_len`; when larger, update `max_len` and save `yytext`.
3. Print the longest word and its character length.

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
./main sample_input.txt
```

## Sample Input
```
Lexical analysis is the fundamental preprocessing stage in modern compiler construction.
```

## Output
```text
====================================================
          FIND LENGTH OF LONGEST WORD (LEX)         
====================================================
Longest Word : 'preprocessing'
Length       : 13 characters
----------------------------------------------------
```

## Result
The program accurately identified the longest word (`preprocessing`, 13 characters) in the input.
