# Experiment 22: Print All HTML Tags

## Aim
Write a LEX program to extract and display all HTML tags from an HTML file (`sample.html`).

## Algorithm
1. Define the LEX rule `\<[^>]*\>` to recognize opening and closing HTML tags.
2. Suppress non-tag text content using `.|\n`.
3. Print each recognized HTML tag sequentially along with the total tag count.

## Source Files
- `main.l`: Source implementation.
- `sample.html`: Sample input file.

## Compilation
```bash
flex main.l
gcc -std=c11 -Wall -Wextra -O2 lex.yy.c -o main -lfl
```

## Execution
```bash
./main sample.html
```

## Sample Input
```
<html>
<body>
<h1>My First Heading</h1>
<p>My first paragraph.</p>
</body>
</html>
```

## Output
```text
====================================================
             HTML TAG EXTRACTOR (LEX)               
====================================================
Extracted HTML Tags from sample.html:
----------------------------------------------------
Tag 1: <html>
Tag 2: <body>
Tag 3: <h1>
Tag 4: </h1>
Tag 5: <p>
Tag 6: </p>
Tag 7: </body>
Tag 8: </html>
----------------------------------------------------
Total HTML Tags Found: 8
```

## Result
All opening and closing HTML tags in `sample.html` were extracted and printed cleanly.
