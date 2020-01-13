#include "pathfinder.h"

void mx_print_matrix(t_unit **adj_matrix, int msize) {
    printf("|n|");
    for (int i = 1; i < msize; i++) {
        printf("|%s|", adj_matrix[i][0].isld);
    }
    printf("\n");
    for (int i = 1; i < msize; i++) {
        for (int j = 0; j < msize; j++) {
            if (j == 0) {
                printf("|%s|", adj_matrix[i][j].isld);
                continue;
            }
            // if (adj_matrix[i][0].isld != NULL) {
                // printf("|%s|", adj_matrix[i][0].isld);
                // // continue;
            // }
            // if (adj_matrix[0][j].isld != NULL) {
                // printf("|%s|", adj_matrix[0][j].isld);
                // // continue;
            // }
            // if (adj_matrix[i][j].dist != NULL)
                // printf("|%s|", adj_matrix[i][j].dist);
            if (adj_matrix[i][j].dist != NULL)
                printf("|%d|", mx_count_dist(adj_matrix[i][j].dist));
            else
                printf("|n|");
        }
        printf("\n");
    } 
}

