# Experiment 01: Lexical Analyzer

## Aim
Develop a Lexical Analyzer in C to identify identifiers, constants, and operators from a given C source program while ignoring redundant spaces, tabs, newlines, and comments.

## Algorithm
1. Open the source file or accept input from the standard input stream.
2. Read the source program character by character.
3. Skip all whitespace characters (spaces, tabs, carriage returns) and track line numbers using newline characters.
4. Detect and bypass comments:
   - For `//`, skip all characters until end-of-line (`\n`).
   - For `/*`, skip all characters until the closing `*/` delimiter.
5. If an alphabetic character or underscore is encountered, read the complete alphanumeric word. Compare against standard C keywords to categorize as `KEYWORD` or `IDENTIFIER`.
6. If a numeric digit is encountered, read the numeric string (including optional decimal point) and categorize as `INTEGER CONSTANT` or `FLOAT CONSTANT`.
7. If an operator symbol (`+`, `-`, `*`, `/`, `=`, `<`, `>`, `!`, etc.) is detected, check for multi-character operators (`++`, `--`, `==`, `<=`, etc.) and classify as `OPERATOR`.
8. Classify punctuation and delimiters (`;`, `,`, `(`, `)`, `{`, `}`) as `DELIMITER`.
9. Display each token alongside its recognized category in a formatted table.

## Source Files
- `main.c`: Lexical analyzer source implementation in C.
- `sample_input.c`: Test C source program containing keywords, identifiers, constants, operators, and comments.

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
```

## Execution
```bash
./main sample_input.c
```

## Sample Input
```c
// Sample C program for lexical analysis
#include <stdio.h>

int main() {
    /* Variable declarations */
    int number1 = 10;
    float sum = 25.5;
    if (number1 >= 5) {
        sum = sum + number1;
    }
    return 0;
}
```

## Output
```text
====================================================
         LEXICAL ANALYZER (C IMPLEMENTATION)        
====================================================
TOKEN                CATEGORY            
----------------------------------------------------
#include             PREPROCESSOR        
<                    OPERATOR            
stdio                IDENTIFIER          
int                  KEYWORD             
main                 IDENTIFIER          
(                    DELIMITER           
)                    DELIMITER           
{                    DELIMITER           
int                  KEYWORD             
number1              IDENTIFIER          
=                    OPERATOR            
10                   INTEGER CONSTANT    
;                    DELIMITER           
float                KEYWORD             
sum                  IDENTIFIER          
=                    OPERATOR            
25.5                 FLOAT CONSTANT      
;                    DELIMITER           
if                   KEYWORD             
(                    DELIMITER           
number1              IDENTIFIER          
>=                   OPERATOR            
5                    INTEGER CONSTANT    
)                    DELIMITER           
{                    DELIMITER           
sum                  IDENTIFIER          
=                    OPERATOR            
sum                  IDENTIFIER          
+                    OPERATOR            
number1              IDENTIFIER          
;                    DELIMITER           
}                    DELIMITER           
return               KEYWORD             
0                    INTEGER CONSTANT    
;                    DELIMITER           
}                    DELIMITER           
----------------------------------------------------
Lexical analysis complete.
```

## Result
The Lexical Analyzer program was written, compiled with GCC, and executed successfully. It accurately identified all identifiers, constants, keywords, and operators while eliminating comments and whitespace.

