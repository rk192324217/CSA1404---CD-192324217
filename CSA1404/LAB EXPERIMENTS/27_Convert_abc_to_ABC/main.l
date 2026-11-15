%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int replacements = 0;
%}

%%
"abc"   { printf("ABC"); replacements++; }
\r      { /* ignore CR */ }
.|\n    { putchar(yytext[0]); }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("      CONVERT SUBSTRING 'abc' TO 'ABC' (LEX)        \n");
    printf("====================================================\n");
    printf("Converted Output:\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Total 'abc' -> 'ABC' conversions: %d\n", replacements);
    return 0;
}

