# Experiment 13: Bottom-Up Shift-Reduce Parsing for Grammar Check

## Aim
Implement a bottom-up Shift-Reduce parser in C to check whether an input string satisfies the expression grammar `E -> E+E | E*E | (E) | id`.

## Algorithm
1. Maintain a parsing stack and an input scan index.
2. Shift each incoming token (`id`, `+`, `*`, `(`, `)`) onto the stack.
3. Repeatedly check the top of the stack for handles matching `id`, `(E)`, `E+E`, or `E*E` and reduce them to `E`.
4. Accept the input string if the stack reduces strictly to start symbol `E` after consuming all tokens.

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
id+id*id
id+*id
```

## Output
```text
========================================================
     BOTTOM-UP SHIFT-REDUCE PARSER (GRAMMAR CHECK)      
========================================================
Grammar: E -> E+E | E*E | (E) | id

Parsing String: id+id*id
STACK              INPUT              ACTION              
--------------------------------------------------------
id                 +id*id             SHIFT id
E                                     REDUCE E -> id
E+                 id*id              SHIFT +
E+id               *id                SHIFT id
E+E                                   REDUCE E -> id
E                                     REDUCE E -> E+E
E*                 id                 SHIFT *
E*id                                  SHIFT id
E*E                                   REDUCE E -> id
E                                     REDUCE E -> E*E
RESULT: 'id+id*id' -> ACCEPTED (Satisfies Grammar)

Parsing String: id+*id
STACK              INPUT              ACTION              
--------------------------------------------------------
id                 +*id               SHIFT id
E                                     REDUCE E -> id
E+                 *id                SHIFT +
E+*                id                 SHIFT *
E+*id                                 SHIFT id
E+*E                                  REDUCE E -> id
RESULT: 'id+*id' -> REJECTED (Does not satisfy Grammar)
========================================================
```

## Result
The shift-reduce parser traced every shift/reduce step and accurately accepted valid expressions while rejecting invalid ones.
