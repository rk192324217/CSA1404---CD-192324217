%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int tag_count = 0;
%}

%%
\<[^>]*\>   { tag_count++; printf("Tag %d: %s\n", tag_count, yytext); }
.|\n        { /* ignore text outside tags */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample.html";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open '%s'\n", filename);
        return 1;
    }
    yyin = fp;

    printf("====================================================\n");
    printf("             HTML TAG EXTRACTOR (LEX)               \n");
    printf("====================================================\n");
    printf("Extracted HTML Tags from %s:\n", filename);
    printf("----------------------------------------------------\n");
    yylex();
    fclose(fp);
    printf("----------------------------------------------------\n");
    printf("Total HTML Tags Found: %d\n", tag_count);
    return 0;
}

