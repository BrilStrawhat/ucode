#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include "stdio.h"

// Enums
typedef enum e_error {
    INVALID_ARGUMENTS_COUNT,
    FILE_DOES_NOT_EXISTS,
    FILE_IS_EMPTY,
    INVALID_FIRST_LINE,
    INVALID_LINE,
    INVALID_ISLANDS_COUNT
} t_error;

void mx_three_to_one(char *first_part, char *text, char *second_part);
void mx_error_handler(t_error error, char *filename, char *text);
void mx_set_arr_null(int size_row, int size_col, char *arr[size_row][size_col]);
char *mx_strjoin_del(char *s1, const char *s2);
char *mx_strdup_del(char *str);

#endif
