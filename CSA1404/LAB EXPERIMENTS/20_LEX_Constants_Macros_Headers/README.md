# Experiment 20: LEX Constants, Macros, and Header Files Identifier

## Aim
Write a LEX program to identify all constants in a C source file (`sample.c`) and count `#define` macros and `#include` header files.

## Algorithm
1. Define patterns for `#define` macro directives and `#include` header lines and increment their counters.
2. Match floating-point constants, integer constants, and string literals and print each found constant.
3. Summarize total constants, defined macros, and included header files.

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
#define PI 3.14
#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c = 30;
printf("hello");
}
```

## Output
```text
====================================================
  LEX: CONSTANTS, MACROS & HEADER FILES IDENTIFIER  
====================================================
MACRO DEFINED     : #define PI
FLOAT CONSTANT    : 3.14
HEADER INCLUDED   : #include<stdio.h>
HEADER INCLUDED   : #include<conio.h>
INTEGER CONSTANT  : 30
STRING CONSTANT   : "hello"
----------------------------------------------------
Total Constants Identified   : 3
Number of Macros Defined     : 1
Number of Header Files       : 2
----------------------------------------------------
```

## Result
The program successfully identified `3.14`, `30`, and `"hello"` constants along with 1 macro and 2 header files.
