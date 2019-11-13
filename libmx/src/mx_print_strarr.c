#include "libmx.h"

void  mx_print_strarr(char **arr, const char *delim) {
    for (int i = 0; arr[i] != '\0'; i++) {
        mx_printstr(arr[i]);
        mx_printstr(delim);
    }
    mx_printchar('\n');
}
