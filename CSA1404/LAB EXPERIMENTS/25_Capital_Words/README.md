# Experiment 25: Identify Capital Words

## Aim
Write a LEX program to identify and print all fully uppercase (capital) words from the input text.

## Algorithm
1. Match alphabetic words using `[A-Za-z]+`.
2. Verify that every character in `yytext` is uppercase using `isupper()`.
3. Print each verified capital word and report the total count.

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
SAVEETHA School of ENGINEERING teaches COMPILER DESIGN using FLEX and GCC tools.
```

## Output
```text
====================================================
          IDENTIFY CAPITAL WORDS (LEX)              
====================================================
Capital Word 1: SAVEETHA
Capital Word 2: ENGINEERING
Capital Word 3: COMPILER
Capital Word 4: DESIGN
Capital Word 5: FLEX
Capital Word 6: GCC
----------------------------------------------------
Total Capital Words Found: 6
```

## Result
Only fully uppercase words were extracted and counted accurately.
