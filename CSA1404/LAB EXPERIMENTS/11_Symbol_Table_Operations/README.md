# Experiment 11: Symbol Table Operations

## Aim
Implement a C program to perform symbol table operations including Insert, Search, Modify, Delete, and Display.

## Algorithm
1. Define a `Symbol` structure storing identifier name, data type, memory size, and address.
2. Implement `INSERT` with duplicate checking, `SEARCH` by identifier name, `MODIFY` to update attributes, `DELETE` by shifting records, and `DISPLAY` to print the table.
3. Parse command sequences from standard input and execute each operation sequentially.

## Source Files
- `main.c`: Source implementation.
- `sample_input.txt`: Sample input file.

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
```

## Execution
```bash
./main < sample_input.txt
```

## Sample Input
```
INSERT x int 4 1000
INSERT sum float 4 1004
INSERT flag char 1 1008
INSERT count int 4 1012
DISPLAY
SEARCH sum
MODIFY sum double 8 1004
DELETE flag
DISPLAY
EXIT
```

## Output
```text
====================================================
            SYMBOL TABLE OPERATIONS (C)             
====================================================
[INSERT] Added: x          Type: int      Size: 4    Addr: 1000
[INSERT] Added: sum        Type: float    Size: 4    Addr: 1004
[INSERT] Added: flag       Type: char     Size: 1    Addr: 1008
[INSERT] Added: count      Type: int      Size: 4    Addr: 1012
----------------------------------------------------
SYMBOL       TYPE       SIZE     ADDRESS   
----------------------------------------------------
x            int        4        1000      
sum          float      4        1004      
flag         char       1        1008      
count        int        4        1012      
----------------------------------------------------
[SEARCH] Found 'sum' -> Type: float, Size: 4, Addr: 1004
[MODIFY] Updated 'sum' -> Type: double, Size: 8, Addr: 1004
[DELETE] Removed symbol 'flag'.
----------------------------------------------------
SYMBOL       TYPE       SIZE     ADDRESS   
----------------------------------------------------
x            int        4        1000      
sum          double     8        1004      
count        int        4        1012      
----------------------------------------------------
```

## Result
All symbol table operations (Insert, Search, Modify, Delete, Display) executed reliably without duplicates or errors.
