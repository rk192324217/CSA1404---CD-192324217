%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

int valid_count = 0;
int invalid_count = 0;
%}

%%
^[ \t]*(\+|\-|\*|\/)[ \t]*\r?$ {
    char op = '\0';
    for (int i = 0; yytext[i]; i++) {
        if (yytext[i] == '+' || yytext[i] == '-' || yytext[i] == '*' || yytext[i] == '/') {
            op = yytext[i];
            break;
        }
    }
    const char *name = (op == '+') ? "Addition" :
                       (op == '-') ? "Subtraction" :
                       (op == '*') ? "Multiplication" : "Division";
    printf("%-15c -> VALID ARITHMETIC OPERATOR (%s)\n", op, name);
    valid_count++;
}
^[ \t]*\r?$ { /* ignore blank lines */ }
[^\r\n]+ {
    printf("%-15s -> INVALID ARITHMETIC OPERATOR\n", yytext);
    invalid_count++;
}
\r?\n { /* consume newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("       ARITHMETIC OPERATOR VALIDATOR (+,-,*,/)      \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Valid operators: %d | Invalid inputs: %d\n", valid_count, invalid_count);
    return 0;
}
