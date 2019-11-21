#include "libmx.h"

char *mx_itoa(int number) {
    int size = 0;
    char *result;

    for (int i = number; i != 0; i /= 10, size++);
    result = malloc(size * sizeof(char));
    result[size] = '\0';
    for (int i = size - 1; i >= 0; i--, number /= 10)
        result[i] = number % 10 + 48;
    return result;
} 
