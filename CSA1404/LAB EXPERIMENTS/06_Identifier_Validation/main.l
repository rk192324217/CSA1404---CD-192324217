%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <string.h>

static const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
static const int num_kw = sizeof(keywords) / sizeof(keywords[0]);

int is_keyword(const char *s) {
    for (int i = 0; i < num_kw; i++) {
        if (strcmp(s, keywords[i]) == 0) return 1;
    }
    return 0;
}

int valid_cnt = 0, invalid_cnt = 0;
%}

%%
^[a-zA-Z_][a-zA-Z0-9_]*\r?$ {
    /* Strip trailing \r if present */
    size_t len = strlen(yytext);
    if (len > 0 && yytext[len - 1] == '\r') yytext[len - 1] = '\0';

    if (is_keyword(yytext)) {
        printf("%-20s -> INVALID IDENTIFIER (C Keyword)\n", yytext);
        invalid_cnt++;
    } else {
        printf("%-20s -> VALID IDENTIFIER\n", yytext);
        valid_cnt++;
    }
}
^[ \t]*\r?$ { /* ignore empty lines */ }
[^\r\n]+ {
    printf("%-20s -> INVALID IDENTIFIER\n", yytext);
    invalid_cnt++;
}
\r?\n { /* ignore newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("            IDENTIFIER VALIDATION ANALYZER          \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Valid Identifiers: %d | Invalid Identifiers: %d\n", valid_cnt, invalid_cnt);
    return 0;
}
