# Experiment 03: Ignore Redundant Spaces, Tabs, Newlines, and Comments

## Aim
Design a C lexical analyzer that removes comments and collapses redundant spaces, tabs, and blank newlines from a source program.

## Algorithm
1. Open the input C source file and scan characters sequentially.
2. Skip single-line (`//`) and multi-line (`/* ... */`) comment blocks completely.
3. Collapse consecutive spaces and tabs into at most one space and skip leading whitespace/blank lines.
4. Print the cleaned source code along with summary counts of skipped comments, spaces, and blank lines.

## Source Files
- `main.c`: Source implementation.
- `sample_input.c`: Sample input file.

## Compilation
```bash
gcc -std=c11 -Wall -Wextra -O2 main.c -o main
```

## Execution
```bash
./main sample_input.c
```

## Sample Input
```
// Single line comment to ignore
#include <stdio.h>


int   main(  )   {
	/* Multi-line
	   comment block */
	int    a   =    10;
	int    b   =    20;   // inline comment
	printf(  "Sum = %d\n",   a   +   b  );

	return   0;
}
```

## Output
```text
====================================================
  CLEANED CODE (SPACES, TABS, NEWLINES & COMMENTS)  
====================================================
#include <stdio.h>
int main( ) {
int a = 10;
int b = 20; 
printf( "Sum = %d\n", a + b );
return 0;
}
----------------------------------------------------
Summary: Comments ignored = 3 | Redundant spaces/tabs skipped = 38 | Blank lines skipped = 5
```

## Result
The program successfully stripped all comments and redundant whitespace while preserving valid program tokens.
