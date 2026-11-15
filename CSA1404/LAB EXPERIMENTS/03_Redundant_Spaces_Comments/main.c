#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample_input.c";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        return 1;
    }

    printf("====================================================\n");
    printf("  CLEANED CODE (SPACES, TABS, NEWLINES & COMMENTS)  \n");
    printf("====================================================\n");

    int ch, prev_space = 0, at_line_start = 1;
    int comments_removed = 0, spaces_skipped = 0, newlines_skipped = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\r') continue;

        /* Detect and ignore comments */
        if (ch == '/') {
            int next = fgetc(fp);
            if (next == '/') {
                comments_removed++;
                while ((ch = fgetc(fp)) != EOF && ch != '\n');
                if (!at_line_start) {
                    putchar('\n');
                    at_line_start = 1;
                    prev_space = 0;
                } else {
                    newlines_skipped++;
                }
                continue;
            } else if (next == '*') {
                comments_removed++;
                int prev = 0;
                while ((ch = fgetc(fp)) != EOF) {
                    if (prev == '*' && ch == '/') break;
                    prev = ch;
                }
                continue;
            } else if (next != EOF) {
                ungetc(next, fp);
            }
        }

        /* Ignore redundant tabs and spaces */
        if (ch == ' ' || ch == '\t') {
            if (at_line_start || prev_space) {
                spaces_skipped++;
            } else {
                putchar(' ');
                prev_space = 1;
            }
            continue;
        }

        /* Ignore blank/redundant newlines */
        if (ch == '\n') {
            if (at_line_start) {
                newlines_skipped++;
            } else {
                putchar('\n');
                at_line_start = 1;
                prev_space = 0;
            }
            continue;
        }

        putchar(ch);
        at_line_start = 0;
        prev_space = 0;
    }

    if (!at_line_start) putchar('\n');
    fclose(fp);

    printf("----------------------------------------------------\n");
    printf("Summary: Comments ignored = %d | Redundant spaces/tabs skipped = %d | Blank lines skipped = %d\n",
           comments_removed, spaces_skipped, newlines_skipped);
    return 0;
}

