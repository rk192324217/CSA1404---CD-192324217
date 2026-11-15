# Experiment 28: Mobile Number Validation

## Aim
Implement a LEX program to verify whether employee mobile numbers are valid 10-digit numbers starting with 6–9.

## Algorithm
1. Define the regular expression `^[6-9][0-9]{9}` matching valid 10-digit Indian mobile numbers.
2. Classify matching numbers as `VALID MOBILE NUMBER` and others as `INVALID MOBILE NUMBER`.
3. Print summary totals of valid and invalid numbers.

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
9876543210
7123456789
5123456789
987654321
98765abc10
6000012345
```

## Output
```text
====================================================
           MOBILE NUMBER VALIDATOR (LEX)            
====================================================
9876543210         -> VALID MOBILE NUMBER
7123456789         -> VALID MOBILE NUMBER
5123456789         -> INVALID MOBILE NUMBER
987654321          -> INVALID MOBILE NUMBER
98765abc10         -> INVALID MOBILE NUMBER
6000012345         -> VALID MOBILE NUMBER
----------------------------------------------------
Valid Numbers: 3 | Invalid Numbers: 3
```

## Result
The mobile number validator accurately accepted valid 10-digit numbers and rejected invalid entries.
