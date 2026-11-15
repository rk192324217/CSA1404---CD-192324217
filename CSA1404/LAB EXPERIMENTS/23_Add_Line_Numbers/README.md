# Experiment 23: Add Line Numbers to a C Source File

## Aim
Write a LEX program to prepend sequential line numbers to every line of a C source file (`sample.c`) and print to stdout.

## Algorithm
1. Match each complete line using `[^\r\n]*\r?\n` (and handle a final line without trailing newline).
2. Increment `line_num` on every matched line and print `line_num: line_content`.
3. Display the total number of numbered lines at the end.

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
         ADD LINE NUMBERS TO C SOURCE FILE          
====================================================
  1: #define PI 3.14
  2: #include<stdio.h>
  3: #include<conio.h>
  4: void main()
  5: {
  6: int a,b,c = 30;
  7: printf("hello");
  8: }
----------------------------------------------------
Total Lines Numbered: 8
```

## Result
The LEX program numbered every line of `sample.c` cleanly on standard output.
