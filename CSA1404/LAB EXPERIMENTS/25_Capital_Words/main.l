%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <ctype.h>

int cap_count = 0;
%}

%%
[A-Za-z]+ {
    int all_upper = 1;
    for (int i = 0; yytext[i] != '\0'; i++) {
        if (!isupper((unsigned char)yytext[i])) {
            all_upper = 0;
            break;
        }
    }
    if (all_upper) {
        cap_count++;
        printf("Capital Word %d: %s\n", cap_count, yytext);
    }
}
[ \t\r\n]+  { /* ignore whitespace */ }
.           { /* ignore punctuation */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("          IDENTIFY CAPITAL WORDS (LEX)              \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Total Capital Words Found: %d\n", cap_count);
    return 0;
}

