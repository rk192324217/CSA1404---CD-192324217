# Experiment 02: Comment Recognition

## Aim
Extend the lexical analyzer using LEX/FLEX to identify whether a given line is a single-line (`//`) or multi-line (`/* ... */`) C comment.

## Algorithm
1. Define LEX regex patterns for single-line (`//.*`) and multi-line (`/* ... */`) C comments.
2. Classify matching comment lines as valid single-line or multi-line comments.
3. Ignore blank whitespace lines and flag any remaining non-comment lines as `NOT A COMMENT`.
4. Compile with `flex` and `gcc` and test against sample input.

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
// This is a single line comment
/* This is a multi line comment */
int a = 10;
printf("Hello, World!");
// Another single comment here
/* Function definition ends */
return 0;
```

## Output
```text
====================================================
       COMMENT RECOGNITION LEXICAL ANALYZER         
====================================================
// This is a single line comment    -> VALID SINGLE-LINE COMMENT
/* This is a multi line comment */  -> VALID MULTI-LINE COMMENT
int a = 10;                         -> NOT A COMMENT
printf("Hello, World!");            -> NOT A COMMENT
// Another single comment here      -> VALID SINGLE-LINE COMMENT
/* Function definition ends */      -> VALID MULTI-LINE COMMENT
return 0;                           -> NOT A COMMENT
----------------------------------------------------
```

## Result
The LEX comment recognition program compiled and executed cleanly, accurately distinguishing single-line comments, multi-line comments, and non-comment code lines.
