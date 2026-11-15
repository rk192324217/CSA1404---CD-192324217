%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

int valid_urls = 0, invalid_urls = 0;
%}

%%
^(https?|ftp):\/\/[a-zA-Z0-9-]+(\.[a-zA-Z0-9-]+)+(:[0-9]+)?(\/[a-zA-Z0-9._~:/?#\[\]@!$&'()*+,;=%-]*)?\r?$ {
    size_t len = strlen(yytext);
    if (len > 0 && yytext[len - 1] == '\r') yytext[len - 1] = '\0';
    printf("%-36s -> VALID URL\n", yytext);
    valid_urls++;
}
^[ \t]*\r?$ { /* ignore blank lines */ }
[^\r\n]+ {
    printf("%-36s -> INVALID URL\n", yytext);
    invalid_urls++;
}
\r?\n { /* consume newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("               URL VALIDATOR (LEX)                  \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Valid URLs: %d | Invalid URLs: %d\n", valid_urls, invalid_urls);
    return 0;
}

