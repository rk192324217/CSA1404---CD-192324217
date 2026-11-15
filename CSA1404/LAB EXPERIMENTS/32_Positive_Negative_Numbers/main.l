%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int positive_count = 0;
int negative_count = 0;
%}

%%
-[0-9]+(\.[0-9]+)? {
    negative_count++;
    printf("%-15s -> NEGATIVE NUMBER\n", yytext);
}
(\+)?[0-9]+(\.[0-9]+)? {
    positive_count++;
    printf("%-15s -> POSITIVE NUMBER\n", yytext);
}
[ \t\r\n,]+ { /* ignore separators */ }
.           { /* ignore non-numeric chars */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("     POSITIVE AND NEGATIVE NUMBERS COUNTER (LEX)    \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Positive Numbers: %d | Negative Numbers: %d\n", positive_count, negative_count);
    return 0;
}

