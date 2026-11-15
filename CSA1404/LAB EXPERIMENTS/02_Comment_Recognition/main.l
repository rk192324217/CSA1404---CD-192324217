%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
%}

%%
"//".*                      { printf("%-35s -> VALID SINGLE-LINE COMMENT\n", yytext); }
"/*"([^*]|\*+[^*/])*\*+"/"  { printf("%-35s -> VALID MULTI-LINE COMMENT\n", yytext); }
[ \t\r\n]+                  { /* Ignore whitespace */ }
[^\r\n]+                    { printf("%-35s -> NOT A COMMENT\n", yytext); }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("       COMMENT RECOGNITION LEXICAL ANALYZER         \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    return 0;
}
