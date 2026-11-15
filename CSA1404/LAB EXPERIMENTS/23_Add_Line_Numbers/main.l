%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int line_num = 0;
%}

%%
[^\r\n]*\r?\n   {
    line_num++;
    printf("%3d: %s", line_num, yytext);
}
[^\r\n]+        {
    line_num++;
    printf("%3d: %s\n", line_num, yytext);
}
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample.c";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open '%s'\n", filename);
        return 1;
    }
    yyin = fp;

    printf("====================================================\n");
    printf("         ADD LINE NUMBERS TO C SOURCE FILE          \n");
    printf("====================================================\n");
    yylex();
    fclose(fp);
    printf("----------------------------------------------------\n");
    printf("Total Lines Numbered: %d\n", line_num);
    return 0;
}

