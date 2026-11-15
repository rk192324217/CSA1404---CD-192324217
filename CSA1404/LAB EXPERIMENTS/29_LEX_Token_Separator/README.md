# Experiment 29: LEX Token Separator for C Program

## Aim
Implement a LEX/FLEX lexical analyzer to separate tokens in `sample.c` and display each with its appropriate token caption.

## Algorithm
1. Define LEX patterns for preprocessor directives, all 32 C keywords, identifiers, integer/float constants, string literals, operators, and separators.
2. Print each extracted lexeme alongside its caption.
3. Count and print the total number of tokens extracted.

## Source Files
- `main.l`: Source implementation.
- `sample.c`: Sample input file.

## Compilation
```bash
flex main.l
gcc -std=c11 -Wall -Wextra -O2 lex.yy.c -o main -lfl
```

## Execution
```bash
./main sample.c
```

## Sample Input
```
#include<stdio.h>
void main()
{
int a,b,c = 30;
printf("hello");
}
```

## Output
```text
====================================================
     LEXICAL ANALYZER: C TOKEN SEPARATOR (FLEX)     
====================================================
TOKEN                     CAPTION                  
----------------------------------------------------
#include<stdio.h>      -> PREPROCESSOR DIRECTIVE
void                   -> KEYWORD
main                   -> IDENTIFIER
(                      -> SEPARATOR / DELIMITER
)                      -> SEPARATOR / DELIMITER
{                      -> SEPARATOR / DELIMITER
int                    -> KEYWORD
a                      -> IDENTIFIER
,                      -> SEPARATOR / DELIMITER
b                      -> IDENTIFIER
,                      -> SEPARATOR / DELIMITER
c                      -> IDENTIFIER
=                      -> OPERATOR
30                     -> INTEGER CONSTANT
;                      -> SEPARATOR / DELIMITER
printf                 -> IDENTIFIER
(                      -> SEPARATOR / DELIMITER
"hello"                -> STRING LITERAL
)                      -> SEPARATOR / DELIMITER
;                      -> SEPARATOR / DELIMITER
}                      -> SEPARATOR / DELIMITER
----------------------------------------------------
Total Tokens Extracted: 21
```

## Result
All tokens in `sample.c` were cleanly separated and labeled with captions.
