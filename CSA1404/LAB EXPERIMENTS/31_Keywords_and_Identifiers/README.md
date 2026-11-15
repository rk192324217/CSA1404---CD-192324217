# Experiment 31: Separate Keywords and Identifiers

## Aim
Write a LEX program to distinguish and separate the 32 C keywords from user-defined identifiers.

## Algorithm
1. List all 32 C keywords in a prioritized LEX rule before the identifier rule.
2. Match remaining valid identifiers using `[a-zA-Z_][a-zA-Z0-9_]*`.
3. Display each lexeme as `KEYWORD` or `IDENTIFIER` with total counts.

## Source Files
- `main.l`: Source implementation.
- `sample_input.c`: Sample input file.

## Compilation
```bash
flex main.l
gcc -std=c11 -Wall -Wextra -O2 lex.yy.c -o main -lfl
```

## Execution
```bash
./main sample_input.c
```

## Sample Input
```
int main() {
    float avg, total_sum;
    while (avg >= 10) {
        for (int i = 0; i < 5; i++) {
            total_sum = total_sum + avg;
        }
        break;
    }
    return 0;
}
```

## Output
```text
====================================================
      SEPARATE KEYWORDS AND IDENTIFIERS (LEX)       
====================================================
int                -> KEYWORD
main               -> IDENTIFIER
float              -> KEYWORD
avg                -> IDENTIFIER
total_sum          -> IDENTIFIER
while              -> KEYWORD
avg                -> IDENTIFIER
for                -> KEYWORD
int                -> KEYWORD
i                  -> IDENTIFIER
i                  -> IDENTIFIER
i                  -> IDENTIFIER
total_sum          -> IDENTIFIER
total_sum          -> IDENTIFIER
avg                -> IDENTIFIER
break              -> KEYWORD
return             -> KEYWORD
----------------------------------------------------
Total Keywords: 7 | Total Identifiers: 10
```

## Result
All keywords and identifiers in the input C program were accurately separated.
