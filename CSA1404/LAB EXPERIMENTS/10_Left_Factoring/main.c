#include <stdio.h>
#include <string.h>

#define MAX_PRODS 10
#define MAX_LEN 32

/* Grammar from PDF Experiment 10:
 * S -> iEtS / iEtSeS / a
 * E -> b
 */
typedef struct {
    char lhs;
    char prods[MAX_PRODS][MAX_LEN];
    int count;
} CFG;

int common_prefix_len(const char *s1, const char *s2) {
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) {
        i++;
    }
    return i;
}

int main(void) {
    CFG rules[2] = {
        { 'S', { "iEtS", "iEtSeS", "a" }, 3 },
        { 'E', { "b" }, 1 }
    };
    int num_rules = 2;

    printf("====================================================\n");
    printf("        ELIMINATION OF LEFT FACTORING (CFG)         \n");
    printf("====================================================\n");
    printf("Original Grammar:\n");
    for (int i = 0; i < num_rules; i++) {
        printf("  %c -> ", rules[i].lhs);
        for (int j = 0; j < rules[i].count; j++) {
            printf("%s", rules[i].prods[j]);
            if (j < rules[i].count - 1) printf(" | ");
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n");
    printf("Grammar After Left Factoring:\n");

    for (int i = 0; i < num_rules; i++) {
        char A = rules[i].lhs;
        if (rules[i].count < 2) {
            printf("  %c  -> %s\n", A, rules[i].prods[0]);
            continue;
        }

        /* Find longest common prefix among pairs */
        int best_len = 0;
        char prefix[MAX_LEN] = "";
        for (int j = 0; j < rules[i].count; j++) {
            for (int k = j + 1; k < rules[i].count; k++) {
                int plen = common_prefix_len(rules[i].prods[j], rules[i].prods[k]);
                if (plen > best_len) {
                    best_len = plen;
                    strncpy(prefix, rules[i].prods[j], (size_t)plen);
                    prefix[plen] = '\0';
                }
            }
        }

        if (best_len == 0) {
            printf("  %c  -> ", A);
            for (int j = 0; j < rules[i].count; j++) {
                printf("%s%s", rules[i].prods[j], (j < rules[i].count - 1) ? " | " : "");
            }
            printf("\n");
        } else {
            char suffixes[MAX_PRODS][MAX_LEN];
            int suf_cnt = 0;
            char others[MAX_PRODS][MAX_LEN];
            int oth_cnt = 0;

            for (int j = 0; j < rules[i].count; j++) {
                if (strncmp(rules[i].prods[j], prefix, (size_t)best_len) == 0) {
                    const char *rem = rules[i].prods[j] + best_len;
                    strcpy(suffixes[suf_cnt++], (rem[0] == '\0') ? "eps" : rem);
                } else {
                    strcpy(others[oth_cnt++], rules[i].prods[j]);
                }
            }

            printf("  %c  -> %s%c'", A, prefix, A);
            for (int j = 0; j < oth_cnt; j++) {
                printf(" | %s", others[j]);
            }
            printf("\n");

            printf("  %c' -> ", A);
            for (int j = 0; j < suf_cnt; j++) {
                printf("%s", suffixes[j]);
                if (j < suf_cnt - 1) printf(" | ");
            }
            printf("\n");
        }
    }
    printf("----------------------------------------------------\n");
    return 0;
}

