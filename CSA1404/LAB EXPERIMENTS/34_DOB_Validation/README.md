# Experiment 34: Date of Birth (DOB) Validation

## Aim
Write a LEX program to validate student Dates of Birth (`DD/MM/YYYY`), including calendar and leap-year checks.

## Algorithm
1. Match `DD/MM/YYYY` strings via `^[0-9]{2}\/[0-9]{2}\/[0-9]{4}`.
2. Parse day, month, and year and verify month bounds, days per month, and leap-year rules for February.
3. Classify invalid formats or out-of-range dates as `INVALID DOB`.

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
15/08/2004
29/02/2004
29/02/2005
31/04/2003
12/13/2002
2004-08-15
01/01/2006
```

## Output
```text
====================================================
         DATE OF BIRTH (DOB) VALIDATOR (LEX)        
====================================================
15/08/2004         -> VALID DOB
29/02/2004         -> VALID DOB
29/02/2005         -> INVALID DOB (Calendar out of range)
31/04/2003         -> INVALID DOB (Calendar out of range)
12/13/2002         -> INVALID DOB (Calendar out of range)
2004-08-15         -> INVALID DOB (Format must be DD/MM/YYYY)
01/01/2006         -> VALID DOB
----------------------------------------------------
Valid DOBs: 3 | Invalid DOBs: 4
```

## Result
Valid dates (including leap day 29/02/2004) were accepted while non-leap 29/02/2005 and malformed dates were rejected.
