%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

char old_word[64] = "language";
char new_word[64] = "compiler";
int replace_count = 0;
%}

%%
[a-zA-Z0-9_]+ {
    if (strcmp(yytext, old_word) == 0) {
        fprintf(yyout, "%s", new_word);
        replace_count++;
    } else {
        fprintf(yyout, "%s", yytext);
    }
}
\r      { /* ignore CR */ }
.|\n    { fputc(yytext[0], yyout); }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    const char *in_file = (argc > 1) ? argv[1] : "sample_input.txt";
    const char *out_file = (argc > 2) ? argv[2] : "output.txt";
    if (argc > 3) strncpy(old_word, argv[3], sizeof(old_word) - 1);
    if (argc > 4) strncpy(new_word, argv[4], sizeof(new_word) - 1);

    yyin = fopen(in_file, "r");
    if (!yyin) {
        fprintf(stderr, "Error: Cannot open '%s'\n", in_file);
        return 1;
    }
    yyout = fopen(out_file, "w");
    if (!yyout) {
        fprintf(stderr, "Error: Cannot open '%s'\n", out_file);
        fclose(yyin);
        return 1;
    }

    yylex();
    fclose(yyin);
    fclose(yyout);

    printf("====================================================\n");
    printf("        REPLACE WORD WITH ANOTHER WORD (LEX)        \n");
    printf("====================================================\n");
    printf("Replaced '%s' -> '%s' (%d occurrence(s))\n", old_word, new_word, replace_count);
    printf("Output written to: %s\n", out_file);
    printf("----------------------------------------------------\n");
    printf("Updated File Content:\n");
    FILE *check = fopen(out_file, "r");
    if (check) {
        int ch;
        while ((ch = fgetc(check)) != EOF) putchar(ch);
        fclose(check);
    }
    printf("----------------------------------------------------\n");
    return 0;
}

