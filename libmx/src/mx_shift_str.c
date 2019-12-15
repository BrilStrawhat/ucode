#include "libmx.h"

void mx_shift_str(char *str, int shift) {
    int l = mx_strlen(str);
    int j;
    char buf[l];

    if (l < shift)
        return;
    for (int i = 0; i <= l; i++)
        buf[i] = str[i];
    for (j = 0; j + shift <= l; j++)
        str[j] = buf[j + shift];
}
