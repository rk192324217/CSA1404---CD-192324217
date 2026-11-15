# Experiment 37: Word Frequency Counter in a Sentence

## Aim
Write a LEX program to count the frequency of a specified target word in a sentence or file.

## Algorithm
1. Read the target word from command-line arguments (default `compiler`) and open the input file.
2. Tokenize all alphanumeric words `[a-zA-Z0-9_]+` and compare each against `target_word`.
3. Increment and report the exact frequency count.

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
./main compiler sample_input.txt
```

## Sample Input
```
A compiler translates source code, and an optimizing compiler produces fast target code for the compiler backend.
```

## Output
```text
====================================================
       WORD FREQUENCY COUNTER IN A SENTENCE         
====================================================
Input File   : sample_input.txt
Target Word  : 'compiler'
Frequency    : 3
----------------------------------------------------
```

## Result
The word frequency counter accurately computed occurrences of the target word.
