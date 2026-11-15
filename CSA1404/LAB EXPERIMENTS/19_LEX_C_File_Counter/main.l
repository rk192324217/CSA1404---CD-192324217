%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int nlines = 0;
int nwords = 0;
int nchars = 0;
%}

%%
"//".*                      { /* Ignore single-line comment */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* Ignore multi-line comment */ }
\n                          { nlines++; }
[ \t\r]+                    { /* Ignore redundant spaces and tabs */ }
[^ \t\r\n]+                 { nwords++; nchars += (int)yyleng; }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample.c";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open '%s'\n", filename);
        return 1;
    }
    yyin = fp;
    yylex();
    fclose(fp);

    printf("====================================================\n");
    printf("   LEX C PROGRAM COUNTER (IGNORING SPACES/COMMENTS) \n");
    printf("====================================================\n");
    printf("Source File              : %s\n", filename);
    printf("Number of Lines          : %d\n", nlines);
    printf("Number of Words/Tokens   : %d\n", nwords);
    printf("Number of Non-WS Chars   : %d\n", nchars);
    printf("----------------------------------------------------\n");
    return 0;
}
