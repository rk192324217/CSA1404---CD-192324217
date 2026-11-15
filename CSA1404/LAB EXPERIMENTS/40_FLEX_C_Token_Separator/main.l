%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>

int total_tokens = 0;
%}

%%
"//".*                      { /* Skip single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* Skip multi-line comments */ }
^#include[^\n]*             { total_tokens++; printf("%-20s -> PREPROCESSOR INCLUDE\n", yytext); }
^#define[^\n]*              { total_tokens++; printf("%-20s -> MACRO DEFINITION\n", yytext); }
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" {
    total_tokens++;
    printf("%-20s -> KEYWORD\n", yytext);
}
[a-zA-Z_][a-zA-Z0-9_]* {
    total_tokens++;
    printf("%-20s -> IDENTIFIER\n", yytext);
}
[0-9]+\.[0-9]+ {
    total_tokens++;
    printf("%-20s -> FLOAT CONSTANT\n", yytext);
}
[0-9]+ {
    total_tokens++;
    printf("%-20s -> INTEGER CONSTANT\n", yytext);
}
\"[^\"\n]*\" {
    total_tokens++;
    printf("%-20s -> STRING LITERAL\n", yytext);
}
\'[^\'\n]\' {
    total_tokens++;
    printf("%-20s -> CHAR CONSTANT\n", yytext);
}
"=="|"!="|"<="|">="|"&&"|"||"|"++"|"--"|"="|"+"|"-"|"*"|"/"|"%"|"<"|">"|"!" {
    total_tokens++;
    printf("%-20s -> OPERATOR\n", yytext);
}
[(){}\[\];,] {
    total_tokens++;
    printf("%-20s -> PUNCTUATOR / SEPARATOR\n", yytext);
}
[ \t\r\n]+  { /* Ignore whitespace */ }
.           { /* Ignore stray character */ }
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
    printf("     FLEX C PROGRAM TOKEN SEPARATOR WITH CAPTIONS   \n");
    printf("====================================================\n");
    printf("%-20s    %-24s\n", "LEXEME", "TOKEN CAPTION");
    printf("----------------------------------------------------\n");
    yylex();
    fclose(fp);
    printf("----------------------------------------------------\n");
    printf("Total Tokens Classified: %d\n", total_tokens);
    return 0;
}

