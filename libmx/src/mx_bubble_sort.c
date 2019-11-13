#include "libmx.h"
 
int mx_bubble_sort(char **arr, int size) {
    int iter = 0;
    char *cbuffer;

    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (mx_strcmp(arr[j], arr[j - 1]) < 0) {
                iter++;
                cbuffer = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = cbuffer;
            }
        }
    }
    return iter;
}
