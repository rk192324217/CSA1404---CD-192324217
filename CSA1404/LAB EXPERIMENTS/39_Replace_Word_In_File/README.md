# Experiment 39: Replace a Word with Another Word in a File

## Aim
Write a LEX program to replace every occurrence of a target word with a replacement word in a file.

## Algorithm
1. Open the input file (`yyin`) and output file (`yyout`).
2. Match whole words `[a-zA-Z0-9_]+`; if equal to `old_word`, write `new_word` to `yyout` and increment counter; otherwise preserve `yytext`.
3. Copy all whitespace/punctuation unchanged and display replacement count and updated file content.

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
./main sample_input.txt output.txt
```

## Sample Input
```
The language parser checks syntax, and the language optimizer improves target efficiency.
```

## Output
```text
====================================================
        REPLACE WORD WITH ANOTHER WORD (LEX)        
====================================================
Replaced 'language' -> 'compiler' (2 occurrence(s))
Output written to: output.txt
----------------------------------------------------
Updated File Content:
The compiler parser checks syntax, and the compiler optimizer improves target efficiency.
----------------------------------------------------
```

## Result
All occurrences of `language` were cleanly replaced with `compiler` in `output.txt`.
