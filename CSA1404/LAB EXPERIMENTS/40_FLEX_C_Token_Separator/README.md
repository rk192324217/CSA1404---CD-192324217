# Experiment 40: FLEX Program for C Token Separation

## Aim
Write a comprehensive FLEX program to separate tokens in a C program (`sample.c`) and display each with its category caption.

## Algorithm
1. Skip comments (`//`, `/* ... */`) and whitespace.
2. Match preprocessor directives, macros, all 32 C keywords, identifiers, integer/float/char/string constants, operators, and punctuators.
3. Print every token with its caption and total classified token count.

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
#define MAX 100
#include <stdio.h>

int main() {
    int x = 10, y = 20;
    float z = 3.5;
    if (x < y) {
        printf("Valid");
    }
    return 0;
}
```

## Output
```text
====================================================
     FLEX C PROGRAM TOKEN SEPARATOR WITH CAPTIONS   
====================================================
LEXEME                  TOKEN CAPTION           
----------------------------------------------------
#define MAX 100      -> MACRO DEFINITION
#include <stdio.h>   -> PREPROCESSOR INCLUDE
int                  -> KEYWORD
main                 -> IDENTIFIER
(                    -> PUNCTUATOR / SEPARATOR
)                    -> PUNCTUATOR / SEPARATOR
{                    -> PUNCTUATOR / SEPARATOR
int                  -> KEYWORD
x                    -> IDENTIFIER
=                    -> OPERATOR
10                   -> INTEGER CONSTANT
,                    -> PUNCTUATOR / SEPARATOR
y                    -> IDENTIFIER
=                    -> OPERATOR
20                   -> INTEGER CONSTANT
;                    -> PUNCTUATOR / SEPARATOR
float                -> KEYWORD
z                    -> IDENTIFIER
=                    -> OPERATOR
3.5                  -> FLOAT CONSTANT
;                    -> PUNCTUATOR / SEPARATOR
if                   -> KEYWORD
(                    -> PUNCTUATOR / SEPARATOR
x                    -> IDENTIFIER
<                    -> OPERATOR
y                    -> IDENTIFIER
)                    -> PUNCTUATOR / SEPARATOR
{                    -> PUNCTUATOR / SEPARATOR
printf               -> IDENTIFIER
(                    -> PUNCTUATOR / SEPARATOR
"Valid"              -> STRING LITERAL
)                    -> PUNCTUATOR / SEPARATOR
;                    -> PUNCTUATOR / SEPARATOR
}                    -> PUNCTUATOR / SEPARATOR
return               -> KEYWORD
0                    -> INTEGER CONSTANT
;                    -> PUNCTUATOR / SEPARATOR
}                    -> PUNCTUATOR / SEPARATOR
----------------------------------------------------
Total Tokens Classified: 38
```

## Result
The FLEX lexical analyzer separated and labeled all tokens in `sample.c` without errors.
