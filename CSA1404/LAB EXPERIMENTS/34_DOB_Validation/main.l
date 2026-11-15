%top{
#define _POSIX_C_SOURCE 200809L
}
%option nounput noinput
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_dob = 0, invalid_dob = 0;

int is_valid_calendar_date(int d, int m, int y) {
    if (m < 1 || m > 12 || d < 1 || y < 1900 || y > 2099) return 0;
    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int leap = (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    if (leap && m == 2) days_in_month[1] = 29;
    return d <= days_in_month[m - 1];
}
%}

%%
^[0-9]{2}\/[0-9]{2}\/[0-9]{4}\r?$ {
    size_t len = strlen(yytext);
    if (len > 0 && yytext[len - 1] == '\r') yytext[len - 1] = '\0';
    int d = 0, m = 0, y = 0;
    sscanf(yytext, "%d/%d/%d", &d, &m, &y);
    if (is_valid_calendar_date(d, m, y)) {
        printf("%-18s -> VALID DOB\n", yytext);
        valid_dob++;
    } else {
        printf("%-18s -> INVALID DOB (Calendar out of range)\n", yytext);
        invalid_dob++;
    }
}
^[ \t]*\r?$ { /* ignore blank lines */ }
[^\r\n]+ {
    printf("%-18s -> INVALID DOB (Format must be DD/MM/YYYY)\n", yytext);
    invalid_dob++;
}
\r?\n { /* consume newline */ }
%%

int yywrap(void) {
    return 1;
}

int main(void) {
    printf("====================================================\n");
    printf("         DATE OF BIRTH (DOB) VALIDATOR (LEX)        \n");
    printf("====================================================\n");
    yylex();
    printf("----------------------------------------------------\n");
    printf("Valid DOBs: %d | Invalid DOBs: %d\n", valid_dob, invalid_dob);
    return 0;
}

