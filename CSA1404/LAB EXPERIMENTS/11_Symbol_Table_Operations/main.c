#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 50

typedef struct {
    char name[32];
    char type[16];
    int size;
    int address;
} Symbol;

Symbol table[MAX_SYMBOLS];
int count = 0;

int find_symbol(const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) return i;
    }
    return -1;
}

void insert_symbol(const char *name, const char *type, int size, int address) {
    if (find_symbol(name) != -1) {
        printf("[INSERT] Duplicate symbol '%s' already exists.\n", name);
        return;
    }
    if (count >= MAX_SYMBOLS) {
        printf("[INSERT] Symbol table full!\n");
        return;
    }
    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    table[count].size = size;
    table[count].address = address;
    count++;
    printf("[INSERT] Added: %-10s Type: %-8s Size: %-4d Addr: %d\n", name, type, size, address);
}

void search_symbol(const char *name) {
    int idx = find_symbol(name);
    if (idx == -1) {
        printf("[SEARCH] Symbol '%s' NOT found.\n", name);
    } else {
        printf("[SEARCH] Found '%s' -> Type: %s, Size: %d, Addr: %d\n",
               table[idx].name, table[idx].type, table[idx].size, table[idx].address);
    }
}

void modify_symbol(const char *name, const char *new_type, int new_size, int new_addr) {
    int idx = find_symbol(name);
    if (idx == -1) {
        printf("[MODIFY] Symbol '%s' NOT found.\n", name);
        return;
    }
    strcpy(table[idx].type, new_type);
    table[idx].size = new_size;
    table[idx].address = new_addr;
    printf("[MODIFY] Updated '%s' -> Type: %s, Size: %d, Addr: %d\n", name, new_type, new_size, new_addr);
}

void delete_symbol(const char *name) {
    int idx = find_symbol(name);
    if (idx == -1) {
        printf("[DELETE] Symbol '%s' NOT found.\n", name);
        return;
    }
    for (int i = idx; i < count - 1; i++) {
        table[i] = table[i + 1];
    }
    count--;
    printf("[DELETE] Removed symbol '%s'.\n", name);
}

void display_table(void) {
    printf("----------------------------------------------------\n");
    printf("%-12s %-10s %-8s %-10s\n", "SYMBOL", "TYPE", "SIZE", "ADDRESS");
    printf("----------------------------------------------------\n");
    if (count == 0) {
        printf("(Symbol table is empty)\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%-12s %-10s %-8d %-10d\n",
                   table[i].name, table[i].type, table[i].size, table[i].address);
        }
    }
    printf("----------------------------------------------------\n");
}

int main(void) {
    char op[16], name[32], type[16];
    int size, addr;

    printf("====================================================\n");
    printf("            SYMBOL TABLE OPERATIONS (C)             \n");
    printf("====================================================\n");

    while (scanf("%15s", op) == 1) {
        if (strcmp(op, "INSERT") == 0) {
            if (scanf("%31s %15s %d %d", name, type, &size, &addr) == 4) {
                insert_symbol(name, type, size, addr);
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            if (scanf("%31s", name) == 1) search_symbol(name);
        } else if (strcmp(op, "MODIFY") == 0) {
            if (scanf("%31s %15s %d %d", name, type, &size, &addr) == 4) {
                modify_symbol(name, type, size, addr);
            }
        } else if (strcmp(op, "DELETE") == 0) {
            if (scanf("%31s", name) == 1) delete_symbol(name);
        } else if (strcmp(op, "DISPLAY") == 0) {
            display_table();
        } else if (strcmp(op, "EXIT") == 0) {
            break;
        }
    }
    return 0;
}

