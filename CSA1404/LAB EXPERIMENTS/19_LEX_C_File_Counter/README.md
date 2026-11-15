# Experiment 19: LEX C Source Counter (Ignoring Spaces & Comments)

## Aim
Write a LEX specification to count characters, lines, and words in a C program (`sample.c`) while ignoring redundant spaces, tabs, and comments.

## Algorithm
1. Add LEX rules to match and ignore single-line (`//`) and multi-line (`/* ... */`) comments.
2. Skip redundant spaces and tabs while incrementing `nlines` on `\n`.
3. Increment `nwords` and add `yyleng` to `nchars` for each non-whitespace token.
4. Display the final counts for `sample.c`.

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
#include <stdio.h>
int main()
{
int number1, number2, sum;
printf("Enter two integers: ");
scanf("%d %d", &number1, &number2);
sum = number1 + number2;
printf("%d + %d = %d", number1, number2, sum);
return 0;
}
```

## Output
```text
====================================================
   LEX C PROGRAM COUNTER (IGNORING SPACES/COMMENTS) 
====================================================
Source File              : sample.c
Number of Lines          : 10
Number of Words/Tokens   : 33
Number of Non-WS Chars   : 178
----------------------------------------------------
```

## Result
The LEX program accurately processed `sample.c` and printed line, word, and character statistics.
