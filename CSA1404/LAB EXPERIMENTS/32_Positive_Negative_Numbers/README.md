# Experiment 32: Identify and Count Positive and Negative Numbers

## Aim
Write a LEX program to identify and count positive and negative integers and floating-point numbers.

## Algorithm
1. Match negative numbers via `-[0-9]+(\.[0-9]+)?` and increment `negative_count`.
2. Match positive numbers via `(\+)?[0-9]+(\.[0-9]+)?` and increment `positive_count`.
3. Print each recognized number and final positive/negative totals.

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
10 -25 3.14 -0.75 +42 -100 7 99 -8
```

## Output
```text
====================================================
     POSITIVE AND NEGATIVE NUMBERS COUNTER (LEX)    
====================================================
10              -> POSITIVE NUMBER
-25             -> NEGATIVE NUMBER
3.14            -> POSITIVE NUMBER
-0.75           -> NEGATIVE NUMBER
+42             -> POSITIVE NUMBER
-100            -> NEGATIVE NUMBER
7               -> POSITIVE NUMBER
99              -> POSITIVE NUMBER
-8              -> NEGATIVE NUMBER
----------------------------------------------------
Positive Numbers: 5 | Negative Numbers: 4
```

## Result
Positive and negative numbers were accurately classified and counted.
