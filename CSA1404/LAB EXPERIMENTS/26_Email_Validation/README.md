# Experiment 26: Email Address Validation

## Aim
Write a LEX program to validate whether given email addresses conform to valid email syntax.

## Algorithm
1. Match valid email structure `^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.(com|in|org|edu|net)`.
2. Classify matches as `VALID EMAIL ADDRESS` and non-matching lines as `INVALID EMAIL ADDRESS`.
3. Report total valid and invalid email counts.

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
student@saveetha.com
rahul.kumar_99@gmail.in
invalid-email.com
user@.com
admin@college.edu
@missingname.org
```

## Output
```text
====================================================
            EMAIL ADDRESS VALIDATOR (LEX)           
====================================================
student@saveetha.com           -> VALID EMAIL ADDRESS
rahul.kumar_99@gmail.in        -> VALID EMAIL ADDRESS
invalid-email.com              -> INVALID EMAIL ADDRESS
user@.com                      -> INVALID EMAIL ADDRESS
admin@college.edu              -> VALID EMAIL ADDRESS
@missingname.org               -> INVALID EMAIL ADDRESS
----------------------------------------------------
Valid: 3 | Invalid: 3
```

## Result
Valid and invalid email addresses were accurately discriminated.
