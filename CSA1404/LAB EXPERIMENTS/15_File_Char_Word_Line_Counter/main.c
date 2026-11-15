#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample_input.txt";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        return 1;
    }

    int chars = 0, words = 0, lines = 0;
    int in_word = 0;
    int ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\r') continue;
        chars++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace((unsigned char)ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    fclose(fp);

    printf("====================================================\n");
    printf("    LEXICAL ANALYZER: FILE CHAR/WORD/LINE COUNTER   \n");
    printf("====================================================\n");
    printf("File Analyzed    : %s\n", filename);
    printf("Total Characters : %d\n", chars);
    printf("Total Words      : %d\n", words);
    printf("Total Lines      : %d\n", lines);
    printf("----------------------------------------------------\n");
    return 0;
}

