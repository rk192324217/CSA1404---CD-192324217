%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

int valid_emails = 0, invalid_emails = 0;
%}

%%
^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.(com|in|org|edu|net)\r?$ {
    size_t len = strlen(yytext);
    if (len > 0 && yytext[len - 1] == '\r') yytext[len - 1] = '\0';
    printf("%-30s -> VALID EMAIL ADDRESS\n", yytext);
    valid_emails++;
}
^[ \t]*\r?$ { /* ignore blank lines */ }
[^\r\n]+ {
    printf("%-30s -> INVALID EMAIL ADDRESS\n", yytext);
    invalid_emails++;
}
\r?\n { /* consume newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("            EMAIL ADDRESS VALIDATOR (LEX)           \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Valid: %d | Invalid: %d\n", valid_emails, invalid_emails);
    return 0;
}

