#include <stdio.h>
#include <string.h>

/* Shift-Reduce (Bottom-Up) Parser for Expression Grammar:
 * E -> E + E | E * E | ( E ) | id
 */

char stack[128];
int top = -1;

int check_reduce(void) {
    stack[top + 1] = '\0';
    /* Rule: E -> id */
    if (top >= 1 && stack[top - 1] == 'i' && stack[top] == 'd') {
        stack[top - 1] = 'E';
        top--;
        stack[top + 1] = '\0';
        printf("%-18s %-18s REDUCE E -> id\n", stack, "");
        return 1;
    }
    /* Rule: E -> (E) */
    if (top >= 2 && stack[top - 2] == '(' && stack[top - 1] == 'E' && stack[top] == ')') {
        stack[top - 2] = 'E';
        top -= 2;
        stack[top + 1] = '\0';
        printf("%-18s %-18s REDUCE E -> (E)\n", stack, "");
        return 1;
    }
    /* Rule: E -> E + E */
    if (top >= 2 && stack[top - 2] == 'E' && stack[top - 1] == '+' && stack[top] == 'E') {
        stack[top - 2] = 'E';
        top -= 2;
        stack[top + 1] = '\0';
        printf("%-18s %-18s REDUCE E -> E+E\n", stack, "");
        return 1;
    }
    /* Rule: E -> E * E */
    if (top >= 2 && stack[top - 2] == 'E' && stack[top - 1] == '*' && stack[top] == 'E') {
        stack[top - 2] = 'E';
        top -= 2;
        stack[top + 1] = '\0';
        printf("%-18s %-18s REDUCE E -> E*E\n", stack, "");
        return 1;
    }
    return 0;
}

int parse_string(const char *expr) {
    char input[128];
    strcpy(input, expr);
    int len = (int)strlen(input);
    top = -1;
    stack[0] = '\0';

    printf("\nParsing String: %s\n", expr);
    printf("%-18s %-18s %-20s\n", "STACK", "INPUT", "ACTION");
    printf("--------------------------------------------------------\n");

    int i = 0;
    while (i < len) {
        if (input[i] == ' ') {
            i++;
            continue;
        }
        if (strncmp(&input[i], "id", 2) == 0) {
            stack[++top] = 'i';
            stack[++top] = 'd';
            stack[top + 1] = '\0';
            i += 2;
            printf("%-18s %-18s SHIFT id\n", stack, &input[i]);
        } else {
            stack[++top] = input[i];
            stack[top + 1] = '\0';
            i++;
            printf("%-18s %-18s SHIFT %c\n", stack, &input[i], stack[top]);
        }

        while (check_reduce()) {
            /* Keep reducing */
        }
    }

    if (strcmp(stack, "E") == 0) {
        printf("RESULT: '%s' -> ACCEPTED (Satisfies Grammar)\n", expr);
        return 1;
    } else {
        printf("RESULT: '%s' -> REJECTED (Does not satisfy Grammar)\n", expr);
        return 0;
    }
}

int main(void) {
    char line[128];
    printf("========================================================\n");
    printf("     BOTTOM-UP SHIFT-REDUCE PARSER (GRAMMAR CHECK)      \n");
    printf("========================================================\n");
    printf("Grammar: E -> E+E | E*E | (E) | id\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t l = strlen(line);
        while (l > 0 && (line[l - 1] == '\n' || line[l - 1] == '\r')) line[--l] = '\0';
        if (l == 0) continue;
        parse_string(line);
    }
    printf("========================================================\n");
    return 0;
}

