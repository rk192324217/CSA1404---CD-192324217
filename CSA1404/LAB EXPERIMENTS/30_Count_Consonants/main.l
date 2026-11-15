%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int consonant_count = 0;
int vowel_count = 0;
%}

%%
[aeiouAEIOU]    { vowel_count++; printf("%c", yytext[0]); }
[a-zA-Z]        { consonant_count++; printf("%c", yytext[0]); }
\r              { /* ignore CR */ }
.|\n            { printf("%c", yytext[0]); }
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
    printf("====================================================\n");
    printf("          CONSONANT COUNTER IN A SENTENCE           \n");
    printf("====================================================\n");
    printf("Input Text:\n");
    yylex();
    if (argc > 1 && yyin) fclose(yyin);
    printf("\n----------------------------------------------------\n");
    printf("Number of Consonants : %d\n", consonant_count);
    printf("Number of Vowels     : %d\n", vowel_count);
    printf("----------------------------------------------------\n");
    return 0;
}

