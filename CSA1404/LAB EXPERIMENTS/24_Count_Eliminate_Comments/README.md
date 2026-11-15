# Experiment 24: Count and Eliminate Comments from a C File

## Aim
Write a LEX program to count comment lines in `input.c`, eliminate all comments, and write the cleaned code to `output.c`.

## Algorithm
1. Match single-line (`//.*`) and multi-line (`/* ... */`) comments without emitting them to `yyout`.
2. Count each comment line (including embedded newlines inside block comments).
3. Copy all non-comment source code to `output.c`, then display the count and cleaned output.

## Source Files
- `main.l`: Source implementation.
- `input.c`: Sample input file.

## Compilation
```bash
flex main.l
gcc -std=c11 -Wall -Wextra -O2 lex.yy.c -o main -lfl
```

## Execution
```bash
./main input.c output.c
```

## Sample Input
```
#include<stdio.h>
int main()
{
int a,b,c; /*varible declaration*/
printf("enter two numbers");
scanf("%d %d",&a,&b);
c=a+b;//adding two numbers
printf("sum is %d",c);
return 0;
}
```

## Output
```text
====================================================
     COUNT & ELIMINATE COMMENTS FROM C PROGRAM      
====================================================
Number of comment lines removed: 2
Output written to: output.c
----------------------------------------------------
Contents of output.c:
#include<stdio.h>
int main()
{
int a,b,c; 
printf("enter two numbers");
scanf("%d %d",&a,&b);
c=a+b;
printf("sum is %d",c);
return 0;
}
----------------------------------------------------
```

## Result
The program removed all comments from `input.c`, counted the comment lines, and wrote valid C code to `output.c`.
