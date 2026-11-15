# Experiment 30: Count Consonants in a Sentence

## Aim
Implement a LEX program to scan an input sentence and count the number of consonants.

## Algorithm
1. Match vowels `[aeiouAEIOU]` first so they are excluded from the consonant rule.
2. Match remaining letters `[a-zA-Z]` and increment `consonant_count`.
3. Display the total consonant and vowel counts.

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
./main sample_input.txt
```

## Sample Input
```
Lexical analysis splits source code into meaningful tokens.
```

## Output
```text
====================================================
          CONSONANT COUNTER IN A SENTENCE           
====================================================
Input Text:
Lexical analysis splits source code into meaningful tokens.

----------------------------------------------------
Number of Consonants : 31
Number of Vowels     : 20
----------------------------------------------------
```

## Result
The consonant counter accurately counted all consonants in the given sentence.
