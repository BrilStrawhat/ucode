#include "libmx.h"

char *mx_itoa(int number) {
    int size = 0;
    char *result;
    int costil = 1;

    for (int i = number; i != 0; i /= 10, size++);
    if (number < 0) {
        size++;
        costil = -1;
    }
    result = mx_strnew(size);
    for (int i = size - 1; i >= 0; i--, number /= 10) {
        result[i] = number % 10 * costil + 48;
    }
    if (costil == -1)
        result[0] = '-';
    return result;
} 
