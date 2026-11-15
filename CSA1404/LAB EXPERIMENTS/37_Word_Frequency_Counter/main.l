%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

char target_word[64] = "compiler";
int freq = 0;
%}

%%
[a-zA-Z0-9_]+ {
    if (strcmp(yytext, target_word) == 0) {
        freq++;
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
        strncpy(target_word, argv[1], sizeof(target_word) - 1);
        target_word[sizeof(target_word) - 1] = '\0';
    }
    const char *filename = (argc > 2) ? argv[2] : "sample_input.txt";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open '%s'\n", filename);
        return 1;
    }
    yyin = fp;
    yylex();
    fclose(fp);

    printf("====================================================\n");
    printf("       WORD FREQUENCY COUNTER IN A SENTENCE         \n");
    printf("====================================================\n");
    printf("Input File   : %s\n", filename);
    printf("Target Word  : '%s'\n", target_word);
    printf("Frequency    : %d\n", freq);
    printf("----------------------------------------------------\n");
    return 0;
}

