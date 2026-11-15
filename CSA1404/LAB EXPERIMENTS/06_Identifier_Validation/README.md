# Experiment 06: Identifier Validation

## Aim
Develop a LEX lexical analyzer to validate whether a given string is a valid C identifier.

## Algorithm
1. Match candidate tokens starting with an alphabet or underscore followed by alphanumeric/underscore characters (`[a-zA-Z_][a-zA-Z0-9_]*`).
2. Check matched tokens against the 32 standard C keywords to reject reserved keywords.
3. Classify non-matching lines (e.g., starting with digits or special characters) as `INVALID IDENTIFIER`.
4. Display valid and invalid identifier counts.

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
./main < sample_input.txt
```

## Sample Input
```
sum
_total_1
123abc
my-var
while
counter99
@rate
validName
```

## Output
```text
====================================================
            IDENTIFIER VALIDATION ANALYZER          
====================================================
sum                  -> VALID IDENTIFIER
_total_1             -> VALID IDENTIFIER
123abc               -> INVALID IDENTIFIER
my-var               -> INVALID IDENTIFIER
while                -> INVALID IDENTIFIER (C Keyword)
counter99            -> VALID IDENTIFIER
@rate                -> INVALID IDENTIFIER
validName            -> VALID IDENTIFIER
----------------------------------------------------
Valid Identifiers: 4 | Invalid Identifiers: 4
```

## Result
The identifier validator accurately recognized valid C identifiers and rejected keywords and malformed names.
