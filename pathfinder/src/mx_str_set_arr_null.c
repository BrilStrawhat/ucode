#include "pathfinder.h"

void mx_set_arr_null(int size_row, int size_col,
                     char *arr[size_row][size_col]) {
    int orig = size_col;

    while (size_row >= 0) {
        size_col = orig;
        while (size_col >= 0) {
            arr[size_row][size_col] = NULL;
            size_col--;
        }
        size_row--;
    }
}
