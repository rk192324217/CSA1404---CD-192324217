# Experiment 21: Count Vowels in a Sentence

## Aim
Implement a LEX program to scan an English sentence and count the number of vowels (and consonants).

## Algorithm
1. Match uppercase and lowercase vowels `[aeiouAEIOU]` and increment `vowel_count`.
2. Match remaining alphabetic characters `[a-zA-Z]` and increment `consonant_count`.
3. Print the input sentence followed by the computed vowel and consonant totals.

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
Compiler Design is an essential subject in Computer Science.
```

## Output
```text
====================================================
            VOWEL COUNTER IN A SENTENCE             
====================================================
Input Text:
Compiler Design is an essential subject in Computer Science.

----------------------------------------------------
Number of Vowels     : 20
Number of Consonants : 31
----------------------------------------------------
```

## Result
The vowel counter accurately counted all vowels in the input sentence.
