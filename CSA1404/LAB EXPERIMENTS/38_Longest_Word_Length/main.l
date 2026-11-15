%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

int max_len = 0;
char longest_word[256] = "";
%}

%%
[a-zA-Z]+ {
    if ((int)yyleng > max_len) {
        max_len = (int)yyleng;
        strncpy(longest_word, yytext, sizeof(longest_word) - 1);
        longest_word[sizeof(longest_word) - 1] = '\0';
    }
}
[ \t\r\n]+  { /* ignore whitespace */ }
.           { /* ignore punctuation */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            fprintf(stderr, "Error: Cannot open '%s'\n", argv[1]);
            return 1;
        }
        yyin = fp;
    }
    yylex();
    if (argc > 1 && yyin) fclose(yyin);

    printf("====================================================\n");
    printf("          FIND LENGTH OF LONGEST WORD (LEX)         \n");
    printf("====================================================\n");
    printf("Longest Word : '%s'\n", longest_word);
    printf("Length       : %d characters\n", max_len);
    printf("----------------------------------------------------\n");
    return 0;
}

