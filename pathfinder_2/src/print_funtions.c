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
            if (adj_matrix[i][j].dist != NULL) {
                printf("|%s|", (adj_matrix[i][j].dist));
            }
            else
                printf("|n|");
        }
        // printf("\n\n|!!%s!!|\n\n", (adj_matrix[2][0].isld));
        printf("\n");
    } 
}
void mx_print_result(t_unit **result_matrix, int msize) {
    for (int i = 1; i < msize; i++) {
        for (int j = 2; j < msize; j++) {
            // printf("i = %d j = %d\n", i, j);
            if (i == j)
                continue;
            if (result_matrix[i][j].isld == NULL && result_matrix[i][j].dist == NULL)
                continue;
            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(result_matrix[0][i].isld);
            mx_printstr(" -> ");
            mx_printstr(result_matrix[0][j].isld);
            mx_printstr("\n");
            mx_printstr("Route: ");
            if (result_matrix[i][j].isld == NULL && result_matrix[i][j].dist != NULL) {
                // printf("if\n");
                mx_printstr(result_matrix[0][i].isld);
                mx_printstr(" -> ");
                mx_printstr(result_matrix[0][j].isld);
                mx_printstr("\n");
                mx_printstr("Distance: ");
                mx_printstr(result_matrix[i][j].dist);
                mx_printstr("\n");
            }
            else {
                // printf("else %s\n", result_matrix[0][i].isld);
                // printf("else \n");
                mx_printstr(result_matrix[0][i].isld);
                mx_printstr(" -> ");
                // mx_printstr(result_matrix[i][j].isld);
                mx_printstr(result_matrix[i][j].isld);
                mx_printstr(" -> ");
                mx_printstr(result_matrix[j][0].isld);
                mx_printstr("\n");
                mx_printstr("Distance: ");
                mx_printstr(result_matrix[i][j].dist);
                mx_printstr("\n");
            }
            mx_printstr("========================================\n");
        }
    }
}
