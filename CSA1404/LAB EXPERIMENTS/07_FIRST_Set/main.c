#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODS 10
#define MAX_LEN 20
#define NUM_NT 3

/* Grammar from PDF Experiment 7:
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

int nt_index(char c) {
    for (int i = 0; i < NUM_NT; i++) {
        if (grammar[i].lhs == c) return i;
    }
    return -1;
}

void add_to_set(char *set, char c) {
    size_t len = strlen(set);
    for (size_t i = 0; i < len; i++) {
        if (set[i] == c) return;
    }
    set[len] = c;
    set[len + 1] = '\0';
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

        int all_epsilon = 1;
        for (int k = 0; prod[k] != '\0'; k++) {
            char sub_first[32] = "";
            compute_first(prod[k], sub_first);

            int has_eps = 0;
            for (int j = 0; sub_first[j] != '\0'; j++) {
                if (sub_first[j] == '#') {
                    has_eps = 1;
                } else {
                    add_to_set(result, sub_first[j]);
                }
            }
            if (!has_eps) {
                all_epsilon = 0;
                break;
            }
        }
        if (all_epsilon) {
            add_to_set(result, '#');
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
    printf("      FIRST() SET COMPUTATION - PREDICTIVE PARSER   \n");
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
        printf("FIRST(%c) = ", grammar[i].lhs);
        print_set(first_sets[i]);
        printf("\n");
    }
    printf("----------------------------------------------------\n");
    return 0;
}

