#include "libmx.h"

int mx_atoi(const char *str) {
    int result = 0;
    int minus = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' && mx_isdigit(str[i + 1]) == true) {
            minus = 1;
            continue;
        }
        if (str[i] == '+' && mx_isdigit(str[i + 1]) == true) {
            continue;
        }
        if (mx_isspace(str[i]) == true)
            continue;
        while (mx_isdigit(str[i]) == true) {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        break;
    }
    return minus == 1 ? result * -1: result;
}
