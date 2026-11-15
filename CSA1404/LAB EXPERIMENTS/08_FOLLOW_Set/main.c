#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODS 10
#define MAX_LEN 20
#define NUM_NT 3

/* Grammar from PDF Experiment 8:
 * S -> AaAb | BbBa
 * A -> # (epsilon)
 * B -> # (epsilon)
 */
typedef struct {
    char lhs;
    char rhs[MAX_PRODS][MAX_LEN];
    int count;
} Rule;

Rule grammar[NUM_NT] = {
    { 'S', { "AaAb", "BbBa" }, 2 },
    { 'A', { "#" }, 1 },
    { 'B', { "#" }, 1 }
};

char first_sets[NUM_NT][32];
char follow_sets[NUM_NT][32];

int nt_index(char c) {
    for (int i = 0; i < NUM_NT; i++) {
        if (grammar[i].lhs == c) return i;
    }
    return -1;
}

int add_to_set(char *set, char c) {
    size_t len = strlen(set);
    for (size_t i = 0; i < len; i++) {
        if (set[i] == c) return 0;
    }
    set[len] = c;
    set[len + 1] = '\0';
    return 1;
}

void compute_first(char symbol, char *result) {
    if (!isupper((unsigned char)symbol)) {
        add_to_set(result, symbol);
        return;
    }
    int idx = nt_index(symbol);
    if (idx == -1) return;

    for (int p = 0; p < grammar[idx].count; p++) {
        const char *prod = grammar[idx].rhs[p];
        if (strcmp(prod, "#") == 0) {
            add_to_set(result, '#');
            continue;
        }
        int all_eps = 1;
        for (int k = 0; prod[k] != '\0'; k++) {
            char sub[32] = "";
            compute_first(prod[k], sub);
            int has_eps = 0;
            for (int j = 0; sub[j] != '\0'; j++) {
                if (sub[j] == '#') has_eps = 1;
                else add_to_set(result, sub[j]);
            }
            if (!has_eps) {
                all_eps = 0;
                break;
            }
        }
        if (all_eps) add_to_set(result, '#');
    }
}

void compute_follow_all(void) {
    for (int i = 0; i < NUM_NT; i++) follow_sets[i][0] = '\0';
    add_to_set(follow_sets[0], '$'); /* Start symbol S gets $ */

    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < NUM_NT; i++) {
            char lhs = grammar[i].lhs;
            for (int p = 0; p < grammar[i].count; p++) {
                const char *prod = grammar[i].rhs[p];
                if (strcmp(prod, "#") == 0) continue;
                int len = (int)strlen(prod);

                for (int k = 0; k < len; k++) {
                    if (!isupper((unsigned char)prod[k])) continue;
                    int target_idx = nt_index(prod[k]);
                    if (target_idx == -1) continue;

                    int all_trailing_eps = 1;
                    for (int m = k + 1; m < len; m++) {
                        char sub_first[32] = "";
                        compute_first(prod[m], sub_first);
                        int has_eps = 0;
                        for (int j = 0; sub_first[j] != '\0'; j++) {
                            if (sub_first[j] == '#') has_eps = 1;
                            else if (add_to_set(follow_sets[target_idx], sub_first[j])) changed = 1;
                        }
                        if (!has_eps) {
                            all_trailing_eps = 0;
                            break;
                        }
                    }

                    if (all_trailing_eps) {
                        int lhs_idx = nt_index(lhs);
                        for (int j = 0; follow_sets[lhs_idx][j] != '\0'; j++) {
                            if (add_to_set(follow_sets[target_idx], follow_sets[lhs_idx][j])) {
                                changed = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

void print_set(const char *set) {
    printf("{ ");
    for (size_t i = 0; set[i] != '\0'; i++) {
        if (set[i] == '#') printf("eps");
        else printf("%c", set[i]);
        if (set[i + 1] != '\0') printf(", ");
    }
    printf(" }");
}

int main(void) {
    printf("====================================================\n");
    printf("     FOLLOW() SET COMPUTATION - PREDICTIVE PARSER   \n");
    printf("====================================================\n");
    printf("Given Grammar (eps denotes epsilon):\n");
    for (int i = 0; i < NUM_NT; i++) {
        printf("  %c -> ", grammar[i].lhs);
        for (int j = 0; j < grammar[i].count; j++) {
            printf("%s", strcmp(grammar[i].rhs[j], "#") == 0 ? "eps" : grammar[i].rhs[j]);
            if (j < grammar[i].count - 1) printf(" / ");
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n");

    for (int i = 0; i < NUM_NT; i++) {
        first_sets[i][0] = '\0';
        compute_first(grammar[i].lhs, first_sets[i]);
    }
    compute_follow_all();

    for (int i = 0; i < NUM_NT; i++) {
        printf("FOLLOW(%c) = ", grammar[i].lhs);
        print_set(follow_sets[i]);
        printf("\n");
    }
    printf("----------------------------------------------------\n");
    return 0;
}

