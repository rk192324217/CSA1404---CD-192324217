%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int comment_lines = 0;
%}

%%
"//".*  {
    comment_lines++;
}
"/*"([^*]|\*+[^*/])*\*+"/" {
    comment_lines++;
    for (int i = 0; yytext[i] != '\0'; i++) {
        if (yytext[i] == '\n') comment_lines++;
    }
}
\r      { /* ignore CR */ }
.|\n    { fputc(yytext[0], yyout); }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    const char *in_file = (argc > 1) ? argv[1] : "input.c";
    const char *out_file = (argc > 2) ? argv[2] : "output.c";

    yyin = fopen(in_file, "r");
    if (!yyin) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", in_file);
        return 1;
    }
    yyout = fopen(out_file, "w");
    if (!yyout) {
        fprintf(stderr, "Error: Cannot open output file '%s'\n", out_file);
        fclose(yyin);
        return 1;
    }

    yylex();
    fclose(yyin);
    fclose(yyout);

    printf("====================================================\n");
    printf("     COUNT & ELIMINATE COMMENTS FROM C PROGRAM      \n");
    printf("====================================================\n");
    printf("Number of comment lines removed: %d\n", comment_lines);
    printf("Output written to: %s\n", out_file);
    printf("----------------------------------------------------\n");
    printf("Contents of %s:\n", out_file);

    FILE *check = fopen(out_file, "r");
    if (check) {
        int ch;
        while ((ch = fgetc(check)) != EOF) putchar(ch);
        fclose(check);
    }
    printf("----------------------------------------------------\n");
    return 0;
}

