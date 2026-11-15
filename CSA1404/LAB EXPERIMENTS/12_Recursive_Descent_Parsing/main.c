#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Grammar from PDF Experiment 12:
 * E  -> T E'
 * E' -> + T E' | eps
 * T  -> F T'
 * T' -> * F T' | eps
 * F  -> ( E ) | id
 */

const char *input;
int pos = 0;
int error = 0;

void E(void);
void Eprime(void);
void T(void);
void Tprime(void);
void F(void);

void skip_spaces(void) {
    while (input[pos] == ' ' || input[pos] == '\t') pos++;
}

void E(void) {
    if (error) return;
    T();
    Eprime();
}

void Eprime(void) {
    if (error) return;
    skip_spaces();
    if (input[pos] == '+') {
        pos++;
        T();
        Eprime();
    }
}

void T(void) {
    if (error) return;
    F();
    Tprime();
}

void Tprime(void) {
    if (error) return;
    skip_spaces();
    if (input[pos] == '*') {
        pos++;
        F();
        Tprime();
    }
}

void F(void) {
    if (error) return;
    skip_spaces();
    if (input[pos] == '(') {
        pos++;
        E();
        skip_spaces();
        if (input[pos] == ')') {
            pos++;
        } else {
            error = 1;
        }
    } else if (strncmp(&input[pos], "id", 2) == 0) {
        pos += 2;
    } else if (isalpha((unsigned char)input[pos])) {
        /* Also accept single-letter identifiers like a, b, c */
        pos++;
    } else {
        error = 1;
    }
}

int main(void) {
    char line[128];
    printf("====================================================\n");
    printf("        RECURSIVE DESCENT PARSER (LL(1))            \n");
    printf("====================================================\n");
    printf("Grammar:\n");
    printf("  E  -> TE'       E' -> +TE' | eps\n");
    printf("  T  -> FT'       T' -> *FT' | eps\n");
    printf("  F  -> (E) | id\n");
    printf("----------------------------------------------------\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }
        if (len == 0) continue;

        input = line;
        pos = 0;
        error = 0;
        E();
        skip_spaces();

        if (!error && input[pos] == '\0') {
            printf("Input: %-22s -> ACCEPTED (Valid syntax)\n", line);
        } else {
            printf("Input: %-22s -> REJECTED (Syntax error at pos %d)\n", line, pos);
        }
    }
    printf("----------------------------------------------------\n");
    return 0;
}

