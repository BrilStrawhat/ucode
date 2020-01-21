#include "pathfinder.h"

void mx_check_if_valid_line(char *line, int line_number) {
    int i;

    for (i = 0; line[i] != '-'; i++) {
        if (mx_isalpha(line[i]) == false) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(line_number));
            exit(-1);
        }
    }
    for (i = i + 1; line[i] != ','; i++) {
        if (mx_isalpha(line[i]) == false) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(line_number));
            exit(-1);
        }
    }
    for (i = i + 1; line[i] != '\0'; i++) {
        if (mx_isdigit(line[i]) == false) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(line_number));
            exit(-1);
        }
    }
}    

void mx_error_handler(t_error error, char *filename, char *text) {
    switch (error) {
        case INVALID_ARGUMENTS_COUNT:
            mx_print_error("usage: ./pathfinder [filename]\n");
            break;
        case FILE_DOES_NOT_EXISTS:
            mx_three_to_one("error: file ", filename, " does not exist\n");
            break;
        case FILE_IS_EMPTY:
            mx_three_to_one("error: file ", filename, " is empty\n");
            break;
        case INVALID_FIRST_LINE:
            mx_print_error("error: line 1 is not valid\n");
            break;
        case INVALID_LINE:
            mx_three_to_one("error: line ", text, " is not valid\n");
            break;
        case INVALID_ISLANDS_COUNT:
            mx_print_error("error: invalid number of islands\n");
            break;
    }
}

void mx_three_to_one(char *first_part, char *text, char *second_part) {
    int len1 = mx_strlen(first_part);
    int len2 = mx_strlen(text);
    int len3 = mx_strlen(second_part);
    char *error = mx_strnew(len1 + len2 + len3);

    mx_strcat(error, first_part);
    mx_strcat(error, text);
    mx_strcat(error, second_part);
    mx_print_error(error);
    mx_strdel(&error);
}
