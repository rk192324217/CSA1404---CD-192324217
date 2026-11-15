%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int token_count = 0;
%}

%%
^#include[^\n]*  { token_count++; printf("%-22s -> PREPROCESSOR DIRECTIVE\n", yytext); }
^#define[^\n]*   { token_count++; printf("%-22s -> MACRO DEFINITION\n", yytext); }
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" {
    token_count++;
    printf("%-22s -> KEYWORD\n", yytext);
}
[a-zA-Z_][a-zA-Z0-9_]* {
    token_count++;
    printf("%-22s -> IDENTIFIER\n", yytext);
}
[0-9]+\.[0-9]+ {
    token_count++;
    printf("%-22s -> FLOAT CONSTANT\n", yytext);
}
[0-9]+ {
    token_count++;
    printf("%-22s -> INTEGER CONSTANT\n", yytext);
}
\"[^\"\n]*\" {
    token_count++;
    printf("%-22s -> STRING LITERAL\n", yytext);
}
"=="|"!="|"<="|">="|"++"|"--"|"="|"+"|"-"|"*"|"/"|"<"|">" {
    token_count++;
    printf("%-22s -> OPERATOR\n", yytext);
}
[(){};,] {
    token_count++;
    printf("%-22s -> SEPARATOR / DELIMITER\n", yytext);
}
[ \t\r\n]+  { /* ignore whitespace */ }
.           { /* ignore unrecognized character */ }
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
    printf("     LEXICAL ANALYZER: C TOKEN SEPARATOR (FLEX)     \n");
    printf("====================================================\n");
    printf("%-22s    %-25s\n", "TOKEN", "CAPTION");
    printf("----------------------------------------------------\n");
    yylex();
    fclose(fp);
    printf("----------------------------------------------------\n");
    printf("Total Tokens Extracted: %d\n", token_count);
    return 0;
}

