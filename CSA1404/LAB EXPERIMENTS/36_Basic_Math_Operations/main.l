%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%%
^[ \t]*-?[0-9]+(\.[0-9]+)?[ \t]*[\+\-\*\/][ \t]*-?[0-9]+(\.[0-9]+)?[ \t]*\r?$ {
    double a = 0.0, b = 0.0;
    char op = '\0';
    if (sscanf(yytext, " %lf %c %lf", &a, &op, &b) == 3) {
        size_t len = strlen(yytext);
        while (len > 0 && (yytext[len - 1] == '\r' || yytext[len - 1] == ' ')) yytext[--len] = '\0';
        switch (op) {
            case '+': printf("%-18s = %.2f (Addition)\n", yytext, a + b); break;
            case '-': printf("%-18s = %.2f (Subtraction)\n", yytext, a - b); break;
            case '*': printf("%-18s = %.2f (Multiplication)\n", yytext, a * b); break;
            case '/':
                if (b == 0.0) printf("%-18s -> ERROR: Division by zero\n", yytext);
                else printf("%-18s = %.2f (Division)\n", yytext, a / b);
                break;
        }
    }
}
^[ \t]*\r?$ { /* ignore empty lines */ }
[^\r\n]+ {
    printf("%-18s -> INVALID EXPRESSION\n", yytext);
}
\r?\n { /* consume newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("      BASIC MATHEMATICAL OPERATIONS (LEX)           \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    return 0;
}

