# Experiment 15: File Character, Word, and Line Counter

## Aim
Implement a C lexical analyzer to scan a text file and count the number of characters, words, and lines.

## Algorithm
1. Open the specified file safely and scan characters until `EOF`.
2. Increment character count for every valid character and line count on every `\n`.
3. Track word boundaries using an `in_word` state flag toggled on whitespace transitions.
4. Display total character, word, and line counts.

## Source Files
- `main.c`: Source implementation.
- `sample_input.txt`: Sample input file.

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
```

## Execution
```bash
./main sample_input.txt
```

## Sample Input
```
Compiler design bridges high-level languages and machine code.
Lexical analysis converts source characters into tokens.
Syntax and semantic analysis validate program structure.
Code generation produces target assembly instructions.
```

## Output
```text
====================================================
    LEXICAL ANALYZER: FILE CHAR/WORD/LINE COUNTER   
====================================================
File Analyzed    : sample_input.txt
Total Characters : 232
Total Words      : 28
Total Lines      : 4
----------------------------------------------------
```

## Result
The file counter program accurately scanned the file and reported exact character, word, and line counts.
