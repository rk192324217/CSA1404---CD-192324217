#include <stdio.h>
#include <string.h>

const char *op_to_asm(char op) {
    switch (op) {
        case '+': return "ADD";
        case '-': return "SUB";
        case '*': return "MUL";
        case '/': return "DIV";
        default:  return "NOP";
    }
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample_input.txt";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        return 1;
    }

    printf("====================================================\n");
    printf("       COMPILER BACK END (TARGET CODE GENERATOR)    \n");
    printf("====================================================\n");
    printf("Generating 8086/Register Assembly from Three-Address Code:\n");
    printf("----------------------------------------------------\n");

    char line[128];
    int reg = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) line[--len] = '\0';
        if (len == 0) continue;

        char lhs[32], eq[4], arg1[32], op[4], arg2[32];
        int matched = sscanf(line, "%31s %3s %31s %3s %31s", lhs, eq, arg1, op, arg2);

        printf("; TAC: %s\n", line);
        if (matched == 5) {
            printf("  MOV R%d, %s\n", reg, arg1);
            printf("  %s R%d, %s\n", op_to_asm(op[0]), reg, arg2);
            printf("  MOV %s, R%d\n", lhs, reg);
            reg = (reg + 1) % 4;
        } else if (matched == 3) {
            printf("  MOV R%d, %s\n", reg, arg1);
            printf("  MOV %s, R%d\n", lhs, reg);
            reg = (reg + 1) % 4;
        }
    }

    fclose(fp);
    printf("----------------------------------------------------\n");
    return 0;
}

