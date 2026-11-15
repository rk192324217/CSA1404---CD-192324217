#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Grammar from PDF Experiment 18:
 * E -> E + T | T
 * T -> T * F | F
 * F -> ( E ) | i   (using 'i' to denote terminal 'id')
 */

#define NUM_NT 3

typedef struct {
    char lhs;
    const char *prods[2];
    int count;
} OpRule;

OpRule grammar[NUM_NT] = {
    { 'E', { "E+T", "T" }, 2 },
    { 'T', { "T*F", "F" }, 2 },
    { 'F', { "(E)", "i" }, 2 }
};

char trailing_sets[NUM_NT][32];

int nt_index(char c) {
    for (int i = 0; i < NUM_NT; i++) {
        if (grammar[i].lhs == c) return i;
    }
    return -1;
}

int add_char(char *set, char c) {
    size_t len = strlen(set);
    for (size_t i = 0; i < len; i++) {
        if (set[i] == c) return 0;
    }
    set[len] = c;
    set[len + 1] = '\0';
    return 1;
}

int main(void) {
    for (int i = 0; i < NUM_NT; i++) trailing_sets[i][0] = '\0';

    /* Step 1: Direct terminals in TRAILING */
    for (int i = 0; i < NUM_NT; i++) {
        for (int p = 0; p < grammar[i].count; p++) {
            const char *rhs = grammar[i].prods[p];
            int len = (int)strlen(rhs);
            if (!isupper((unsigned char)rhs[len - 1])) {
                add_char(trailing_sets[i], rhs[len - 1]);
            } else if (len >= 2 && !isupper((unsigned char)rhs[len - 2])) {
                add_char(trailing_sets[i], rhs[len - 2]);
            }
        }
    }

    /* Step 2: Propagate TRAILING(B) into TRAILING(A) for A -> ...B */
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < NUM_NT; i++) {
            for (int p = 0; p < grammar[i].count; p++) {
                const char *rhs = grammar[i].prods[p];
                int len = (int)strlen(rhs);
                if (isupper((unsigned char)rhs[len - 1])) {
                    int b_idx = nt_index(rhs[len - 1]);
                    if (b_idx != -1) {
                        for (int k = 0; trailing_sets[b_idx][k] != '\0'; k++) {
                            if (add_char(trailing_sets[i], trailing_sets[b_idx][k])) {
                                changed = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("====================================================\n");
    printf("   TRAILING() SET - OPERATOR PRECEDENCE PARSER      \n");
    printf("====================================================\n");
    printf("Grammar:\n");
    printf("  E -> E + T | T\n");
    printf("  T -> T * F | F\n");
    printf("  F -> ( E ) | id\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < NUM_NT; i++) {
        printf("TRAILING(%c) = { ", grammar[i].lhs);
        for (size_t k = 0; trailing_sets[i][k] != '\0'; k++) {
            if (trailing_sets[i][k] == 'i') printf("id");
            else printf("%c", trailing_sets[i][k]);
            if (trailing_sets[i][k + 1] != '\0') printf(", ");
        }
        printf(" }\n");
    }
    printf("----------------------------------------------------\n");
    return 0;
}

