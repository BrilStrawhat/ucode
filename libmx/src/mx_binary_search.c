#include "libmx.h"

int mx_binary_search(char** arr, int size, const char *s, int *count) {
    long int mid;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        *count += 1;
        mid = (right + left) / 2;
        if (mx_strcmp(arr[mid], s) == 0)
            return mid;
        if (mx_strcmp(arr[mid], s) > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}       
