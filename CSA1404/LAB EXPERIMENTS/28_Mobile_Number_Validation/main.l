%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

int valid_cnt = 0, invalid_cnt = 0;
%}

%%
^[6-9][0-9]{9}\r?$ {
    size_t len = strlen(yytext);
    if (len > 0 && yytext[len - 1] == '\r') yytext[len - 1] = '\0';
    printf("%-18s -> VALID MOBILE NUMBER\n", yytext);
    valid_cnt++;
}
^[ \t]*\r?$ { /* ignore blank lines */ }
[^\r\n]+ {
    printf("%-18s -> INVALID MOBILE NUMBER\n", yytext);
    invalid_cnt++;
}
\r?\n { /* consume newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("           MOBILE NUMBER VALIDATOR (LEX)            \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Valid Numbers: %d | Invalid Numbers: %d\n", valid_cnt, invalid_cnt);
    return 0;
}

