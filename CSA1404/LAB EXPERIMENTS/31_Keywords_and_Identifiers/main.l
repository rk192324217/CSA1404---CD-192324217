%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int kw_count = 0;
int id_count = 0;
%}

%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" {
    kw_count++;
    printf("%-18s -> KEYWORD\n", yytext);
}
[a-zA-Z_][a-zA-Z0-9_]* {
    id_count++;
    printf("%-18s -> IDENTIFIER\n", yytext);
}
[ \t\r\n]+  { /* ignore whitespace */ }
.           { /* ignore symbols/digits */ }
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
    printf("      SEPARATE KEYWORDS AND IDENTIFIERS (LEX)       \n");
    printf("====================================================\n");
    yylex();
    if (argc > 1 && yyin) fclose(yyin);
    printf("----------------------------------------------------\n");
    printf("Total Keywords: %d | Total Identifiers: %d\n", kw_count, id_count);
    return 0;
}

