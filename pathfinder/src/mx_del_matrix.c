#include "pathfinder.h"

void mx_del_matrix(char ***matrix, int size) {
    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= size; j++) {
            free(matrix[i][j]);
        }
    }
    free(matrix);
}
