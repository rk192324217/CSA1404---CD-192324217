#include <stdio.h>
#include <string.h>

#define MAX_PRODS 10
#define MAX_LEN 32

/* Grammar from PDF Experiment 9:
 * S -> (L) / a
 * L -> L , S / S
 */
typedef struct {
    char lhs;
    char prods[MAX_PRODS][MAX_LEN];
    int count;
} CFG;

int main(void) {
    CFG rules[2] = {
        { 'S', { "(L)", "a" }, 2 },
        { 'L', { "L,S", "S" }, 2 }
    };
    int num_rules = 2;

    printf("====================================================\n");
    printf("        ELIMINATION OF LEFT RECURSION (CFG)         \n");
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
    printf("Grammar After Eliminating Left Recursion:\n");

    for (int i = 0; i < num_rules; i++) {
        char A = rules[i].lhs;
        char alpha[MAX_PRODS][MAX_LEN];
        char beta[MAX_PRODS][MAX_LEN];
        int alpha_cnt = 0, beta_cnt = 0;

        for (int j = 0; j < rules[i].count; j++) {
            if (rules[i].prods[j][0] == A) {
                /* Left recursive: A -> A alpha */
                strcpy(alpha[alpha_cnt++], rules[i].prods[j] + 1);
            } else {
                /* Non-left recursive: A -> beta */
                strcpy(beta[beta_cnt++], rules[i].prods[j]);
            }
        }

        if (alpha_cnt == 0) {
            printf("  %c -> ", A);
            for (int j = 0; j < rules[i].count; j++) {
                printf("%s", rules[i].prods[j]);
                if (j < rules[i].count - 1) printf(" | ");
            }
            printf("\n");
        } else {
            /* Print A -> beta A' */
            printf("  %c  -> ", A);
            for (int j = 0; j < beta_cnt; j++) {
                printf("%s%c'", beta[j], A);
                if (j < beta_cnt - 1) printf(" | ");
            }
            printf("\n");

            /* Print A' -> alpha A' | eps */
            printf("  %c' -> ", A);
            for (int j = 0; j < alpha_cnt; j++) {
                printf("%s%c' | ", alpha[j], A);
            }
            printf("eps\n");
        }
    }
    printf("----------------------------------------------------\n");
    return 0;
}

