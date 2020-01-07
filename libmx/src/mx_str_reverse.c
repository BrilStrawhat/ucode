#include "libmx.h"

void mx_str_reverse(char *s) {
    int length = mx_strlen(s) - 1;
    
    for (int i = 0; i < mx_strlen(s); i++) {
        if (i > length) {
            break;
        }
        mx_swap_char(&s[i], &s[length]);
        length--;
    }
}

