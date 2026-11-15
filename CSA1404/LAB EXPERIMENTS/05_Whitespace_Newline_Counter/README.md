# Experiment 05: Whitespace and Newline Character Counter

## Aim
Design a LEX lexical analyzer to count spaces, tabs, newline characters, and non-whitespace characters in an input file.

## Algorithm
1. Define dedicated LEX rules for space (`" "`), tab (`"\t"`), and newline (`"\n"`).
2. Increment respective counters on each match and count all remaining visible characters.
3. Ignore carriage return (`\r`) characters for cross-platform consistency.
4. Print the individual and total whitespace character counts.

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
int main() {
    int count = 0;
	count = count + 1;
    return 0;
}
```

## Output
```text
====================================================
      WHITESPACE AND NEWLINE CHARACTER COUNTER      
====================================================
Spaces ( )          : 18
Tabs (\t)           : 1
Newlines (\n)       : 5
Total Whitespaces   : 24
Non-whitespace Chars: 44
----------------------------------------------------
```

## Result
The program accurately counted spaces, tabs, newlines, and non-whitespace characters in the input file.
