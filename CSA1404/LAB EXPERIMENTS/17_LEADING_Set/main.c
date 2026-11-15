#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Grammar from PDF Experiment 17:
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

char leading_sets[NUM_NT][32];

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
    for (int i = 0; i < NUM_NT; i++) leading_sets[i][0] = '\0';

    /* Step 1: Direct terminals in LEADING */
    for (int i = 0; i < NUM_NT; i++) {
        for (int p = 0; p < grammar[i].count; p++) {
            const char *rhs = grammar[i].prods[p];
            if (!isupper((unsigned char)rhs[0])) {
                add_char(leading_sets[i], rhs[0]);
            } else if (rhs[1] != '\0' && !isupper((unsigned char)rhs[1])) {
                add_char(leading_sets[i], rhs[1]);
            }
        }
    }

    /* Step 2: Propagate LEADING(B) into LEADING(A) for A -> B... */
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < NUM_NT; i++) {
            for (int p = 0; p < grammar[i].count; p++) {
                const char *rhs = grammar[i].prods[p];
                if (isupper((unsigned char)rhs[0])) {
                    int b_idx = nt_index(rhs[0]);
                    if (b_idx != -1) {
                        for (int k = 0; leading_sets[b_idx][k] != '\0'; k++) {
                            if (add_char(leading_sets[i], leading_sets[b_idx][k])) {
                                changed = 1;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("====================================================\n");
    printf("   LEADING() SET - OPERATOR PRECEDENCE PARSER       \n");
    printf("====================================================\n");
    printf("Grammar:\n");
    printf("  E -> E + T | T\n");
    printf("  T -> T * F | F\n");
    printf("  F -> ( E ) | id\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < NUM_NT; i++) {
        printf("LEADING(%c) = { ", grammar[i].lhs);
        for (size_t k = 0; leading_sets[i][k] != '\0'; k++) {
            if (leading_sets[i][k] == 'i') printf("id");
            else printf("%c", leading_sets[i][k]);
            if (leading_sets[i][k + 1] != '\0') printf(", ");
        }
        printf(" }\n");
    }
    printf("----------------------------------------------------\n");
    return 0;
}

