# Experiment 33: URL Validation

## Aim
Implement a LEX program to validate URLs starting with `http://`, `https://`, or `ftp://`.

## Algorithm
1. Define a regex matching protocol (`http`/`https`/`ftp`), domain labels separated by dots, optional port, and optional path/query.
2. Classify matches as `VALID URL` and malformed strings as `INVALID URL`.
3. Display valid and invalid URL counts.

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
https://www.saveetha.com/csa1404
http://compilerlab.edu.in
ftp://files.example.org/notes
htp://broken-url
www.missing-protocol.com
https://invalid_domain
```

## Output
```text
====================================================
               URL VALIDATOR (LEX)                  
====================================================
https://www.saveetha.com/csa1404     -> VALID URL
http://compilerlab.edu.in            -> VALID URL
ftp://files.example.org/notes        -> VALID URL
htp://broken-url                     -> INVALID URL
www.missing-protocol.com             -> INVALID URL
https://invalid_domain               -> INVALID URL
----------------------------------------------------
Valid URLs: 3 | Invalid URLs: 3
```

## Result
The URL validator accurately validated well-formed URLs and flagged invalid URLs.
