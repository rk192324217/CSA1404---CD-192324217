%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int nmacro = 0;
int nheader = 0;
int nconst = 0;
%}

%%
^[ \t]*#define[ \t]+[A-Za-z_][A-Za-z0-9_]* {
    nmacro++;
    printf("MACRO DEFINED     : %s\n", yytext);
}
^[ \t]*#include[^\n]* {
    nheader++;
    printf("HEADER INCLUDED   : %s\n", yytext);
}
[0-9]+\.[0-9]+ {
    nconst++;
    printf("FLOAT CONSTANT    : %s\n", yytext);
}
[0-9]+ {
    nconst++;
    printf("INTEGER CONSTANT  : %s\n", yytext);
}
\"[^\"\n]*\" {
    nconst++;
    printf("STRING CONSTANT   : %s\n", yytext);
}
[ \t\r\n]+  { /* ignore whitespace */ }
.           { /* ignore other tokens */ }
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

    printf("====================================================\n");
    printf("  LEX: CONSTANTS, MACROS & HEADER FILES IDENTIFIER  \n");
    printf("====================================================\n");
    yylex();
    fclose(fp);
    printf("----------------------------------------------------\n");
    printf("Total Constants Identified   : %d\n", nconst);
    printf("Number of Macros Defined     : %d\n", nmacro);
    printf("Number of Header Files       : %d\n", nheader);
    printf("----------------------------------------------------\n");
    return 0;
}
