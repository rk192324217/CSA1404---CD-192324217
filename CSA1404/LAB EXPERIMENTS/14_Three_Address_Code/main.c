#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR 128

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void generate_tac(const char *stmt) {
    char lhs = '\0';
    char rhs[MAX_EXPR];
    const char *eq = strchr(stmt, '=');

    if (eq) {
        int k = 0;
        while (&stmt[k] < eq && isspace((unsigned char)stmt[k])) k++;
        lhs = stmt[k];
        strcpy(rhs, eq + 1);
    } else {
        strcpy(rhs, stmt);
    }

    /* Convert RHS infix to postfix */
    char postfix[MAX_EXPR];
    char op_stack[MAX_EXPR];
    int p_idx = 0, op_top = -1;

    for (int i = 0; rhs[i] != '\0'; i++) {
        char c = rhs[i];
        if (isspace((unsigned char)c) || c == ';') continue;

        if (isalnum((unsigned char)c)) {
            postfix[p_idx++] = c;
        } else if (c == '(') {
            op_stack[++op_top] = c;
        } else if (c == ')') {
            while (op_top >= 0 && op_stack[op_top] != '(') {
                postfix[p_idx++] = op_stack[op_top--];
            }
            if (op_top >= 0) op_top--;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (op_top >= 0 && precedence(op_stack[op_top]) >= precedence(c)) {
                postfix[p_idx++] = op_stack[op_top--];
            }
            op_stack[++op_top] = c;
        }
    }
    while (op_top >= 0) {
        postfix[p_idx++] = op_stack[op_top--];
    }
    postfix[p_idx] = '\0';

    /* Generate Three Address Code from postfix */
    char val_stack[MAX_EXPR][16];
    int v_top = -1;
    int temp_num = 1;

    printf("Input Statement: %s\n", stmt);
    printf("Three Address Code:\n");
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum((unsigned char)c)) {
            char op_str[2] = { c, '\0' };
            strcpy(val_stack[++v_top], op_str);
        } else {
            char right[16], left[16], temp[16];
            strcpy(right, val_stack[v_top--]);
            strcpy(left, val_stack[v_top--]);
            sprintf(temp, "t%d", temp_num++);
            printf("  %s = %s %c %s\n", temp, left, c, right);
            strcpy(val_stack[++v_top], temp);
        }
    }
    if (lhs != '\0' && v_top >= 0) {
        printf("  %c = %s\n", lhs, val_stack[v_top]);
    }
    printf("----------------------------------------------------\n");
}

int main(void) {
    char line[MAX_EXPR];
    printf("====================================================\n");
    printf("      INTERMEDIATE CODE: THREE ADDRESS CODE (TAC)   \n");
    printf("====================================================\n");

    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) line[--len] = '\0';
        if (len == 0) continue;
        generate_tac(line);
    }
    return 0;
}

