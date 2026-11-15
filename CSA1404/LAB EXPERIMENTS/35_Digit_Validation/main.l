%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

int digit_cnt = 0, non_digit_cnt = 0;
%}

%%
^[0-9]+(\.[0-9]+)?\r?$ {
    size_t len = strlen(yytext);
    if (len > 0 && yytext[len - 1] == '\r') yytext[len - 1] = '\0';
    printf("%-18s -> DIGIT / NUMERIC INPUT\n", yytext);
    digit_cnt++;
}
^[ \t]*\r?$ { /* ignore empty lines */ }
[^\r\n]+ {
    printf("%-18s -> NOT A DIGIT\n", yytext);
    non_digit_cnt++;
}
\r?\n { /* consume newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("             DIGIT CHECKER (LEX PROGRAM)            \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Numeric/Digit Inputs: %d | Non-Digit Inputs: %d\n", digit_cnt, non_digit_cnt);
    return 0;
}

