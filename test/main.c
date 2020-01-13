#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmx.h"

typedef struct str {
    char *str;
    char *isl;
} str;

int main() {
    str **strings = (str**)malloc(6 * sizeof(str*));

    for (int i = 0; i < 6; i++) {
        strings[i] = malloc(sizeof(str) * 6);
    }
    strings[5][5].str = mx_strdup("success");
    strings[5][5].isl = mx_strdup("success");
    printf("%s\n", strings[5][5].str);
    free(strings[5][5].str);
    free(strings[5][5].isl);
    for (int i = 0; i < 6; i++) {
        free(strings[i]);
    }
    free(strings);
    return 0;
}
