#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 64

// List of standard C keywords
static const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
static const int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

int is_keyword(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}

int is_operator_char(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '!' || ch == '&' || ch == '|');
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            fprintf(stderr, "Error opening file: %s\n", argv[1]);
            return 1;
        }
    } else {
        fp = stdin;
    }

    printf("====================================================\n");
    printf("         LEXICAL ANALYZER (C IMPLEMENTATION)        \n");
    printf("====================================================\n");
    printf("%-20s %-20s\n", "TOKEN", "CATEGORY");
    printf("----------------------------------------------------\n");

    int ch;
    int line = 1;
    while ((ch = fgetc(fp)) != EOF) {
        // Count newlines
        if (ch == '\n') {
            line++;
            continue;
        }

        // Ignore redundant spaces and tabs
        if (ch == ' ' || ch == '\t' || ch == '\r') {
            continue;
        }

        // Check for comments
        if (ch == '/') {
            int next_ch = fgetc(fp);
            if (next_ch == '/') {
                // Single-line comment: skip until newline
                while ((ch = fgetc(fp)) != EOF && ch != '\n');
                if (ch == '\n') line++;
                continue;
            } else if (next_ch == '*') {
                // Multi-line comment: skip until */
                int prev = 0;
                while ((ch = fgetc(fp)) != EOF) {
                    if (ch == '\n') line++;
                    if (prev == '*' && ch == '/') break;
                    prev = ch;
                }
                continue;
            } else {
                ungetc(next_ch, fp);
            }
        }

        // Preprocessor directive
        if (ch == '#') {
            char prep[MAX_TOKEN_LEN];
            int idx = 0;
            prep[idx++] = (char)ch;
            while ((ch = fgetc(fp)) != EOF && isalpha(ch) && idx < MAX_TOKEN_LEN - 1) {
                prep[idx++] = (char)ch;
            }
            prep[idx] = '\0';
            printf("%-20s %-20s\n", prep, "PREPROCESSOR");
            if (ch != EOF) ungetc(ch, fp);
            continue;
        }

        // String literals
        if (ch == '"') {
            char str_lit[MAX_TOKEN_LEN];
            int idx = 0;
            str_lit[idx++] = '"';
            while ((ch = fgetc(fp)) != EOF && ch != '"' && idx < MAX_TOKEN_LEN - 2) {
                if (ch == '\n') line++;
                str_lit[idx++] = (char)ch;
            }
            if (ch == '"') str_lit[idx++] = '"';
            str_lit[idx] = '\0';
            printf("%-20s %-20s\n", str_lit, "STRING CONSTANT");
            continue;
        }

        // Numbers (Constants)
        if (isdigit(ch)) {
            char num[MAX_TOKEN_LEN];
            int idx = 0;
            num[idx++] = (char)ch;
            int is_float = 0;
            while ((ch = fgetc(fp)) != EOF && (isdigit(ch) || (ch == '.' && !is_float)) && idx < MAX_TOKEN_LEN - 1) {
                if (ch == '.') is_float = 1;
                num[idx++] = (char)ch;
            }
            num[idx] = '\0';
            printf("%-20s %-20s\n", num, is_float ? "FLOAT CONSTANT" : "INTEGER CONSTANT");
            if (ch != EOF) ungetc(ch, fp);
            continue;
        }

        // Identifiers and Keywords
        if (isalpha(ch) || ch == '_') {
            char ident[MAX_TOKEN_LEN];
            int idx = 0;
            ident[idx++] = (char)ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_') && idx < MAX_TOKEN_LEN - 1) {
                ident[idx++] = (char)ch;
            }
            ident[idx] = '\0';
            if (is_keyword(ident)) {
                printf("%-20s %-20s\n", ident, "KEYWORD");
            } else {
                printf("%-20s %-20s\n", ident, "IDENTIFIER");
            }
            if (ch != EOF) ungetc(ch, fp);
            continue;
        }

        // Multi-character and single-character Operators
        if (is_operator_char(ch)) {
            char op[3] = { (char)ch, '\0', '\0' };
            int next_ch = fgetc(fp);
            if ((ch == '+' && next_ch == '+') ||
                (ch == '-' && next_ch == '-') ||
                (ch == '=' && next_ch == '=') ||
                (ch == '!' && next_ch == '=') ||
                (ch == '<' && next_ch == '=') ||
                (ch == '>' && next_ch == '=') ||
                (ch == '&' && next_ch == '&') ||
                (ch == '|' && next_ch == '|')) {
                op[1] = (char)next_ch;
            } else if (next_ch != EOF) {
                ungetc(next_ch, fp);
            }
            printf("%-20s %-20s\n", op, "OPERATOR");
            continue;
        }

        // Special characters / Delimiters
        if (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            char delim[2] = { (char)ch, '\0' };
            printf("%-20s %-20s\n", delim, "DELIMITER");
            continue;
        }
    }

    if (fp != stdin) {
        fclose(fp);
    }
    printf("----------------------------------------------------\n");
    printf("Lexical analysis complete.\n");
    return 0;
}

