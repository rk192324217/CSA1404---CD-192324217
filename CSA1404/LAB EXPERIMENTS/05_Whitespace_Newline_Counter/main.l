%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int spaces = 0;
int tabs = 0;
int newlines = 0;
int other_chars = 0;
%}

%%
" "     { spaces++; }
"\t"    { tabs++; }
"\n"    { newlines++; }
"\r"    { /* ignore CR */ }
.       { other_chars++; }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            fprintf(stderr, "Error: Cannot open file '%s'\n", argv[1]);
            return 1;
        }
        yyin = fp;
    }

    printf("====================================================\n");
    printf("      WHITESPACE AND NEWLINE CHARACTER COUNTER      \n");
    printf("====================================================\n");
    yylex();
    if (argc > 1 && yyin) fclose(yyin);

    int total_ws = spaces + tabs + newlines;
    printf("Spaces ( )          : %d\n", spaces);
    printf("Tabs (\\t)           : %d\n", tabs);
    printf("Newlines (\\n)       : %d\n", newlines);
    printf("Total Whitespaces   : %d\n", total_ws);
    printf("Non-whitespace Chars: %d\n", other_chars);
    printf("----------------------------------------------------\n");
    return 0;
}
