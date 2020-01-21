#include "pathfinder.h"

void mx_print_parl(t_unit **result_matrix, int msize) {
    t_unit *temp;

    for (int i = 1; i < msize; i++) {
        printf("STEP: %s\n", result_matrix[i][0].isld);
        for (int j = 1; j < msize; j++) {
            if (result_matrix[i][j].parl != NULL) {
                printf("i = %d; j = %d\n", i, j);
                temp = &result_matrix[i][j];
                while (temp != NULL) {
                    printf("%s|", temp->isld);
                    printf("%s\n", temp->dist);
                    temp = temp->parl;
                }
            }
        }
    }
}

void mx_print_matrix(t_unit **adj_matrix, int msize) {
    // printf("|n|");
    for (int i = 0; i < msize; i++) {
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
            // if (adj_matrix[i][j].parl != NULL) {
                // printf("|%s|", (adj_matrix[i][j].parl->isld));
            // }
            else
                printf("|n|");
        }
        // printf("\n\n|!!%s!!|\n\n", (adj_matrix[2][0].isld));
        printf("\n");
    } 
    printf("\n");
}

void print_list(t_unit result_matrix, char *from, char *to) {
    t_unit *temp = &result_matrix;
    while (temp != NULL) {
        // printf("\n\nwhile!!\n\n");
        // printf("%s\n", result_matrix.parl);
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(from);
        mx_printstr(" -> ");
        mx_printstr(to);
        mx_printstr("\n");
        mx_printstr("Route: ");
        mx_printstr(from);
        mx_printstr(" -> ");
        // mx_printstr(result_matrix->isld);
        mx_printstr(temp->isld);
        mx_printstr(" -> ");
        mx_printstr(to);
        mx_printstr("\n");
        mx_printstr("Distance: ");
        mx_printstr(temp->dist);
        mx_printstr(" = ");
        mx_printint(mx_count_dist(temp->dist));
        mx_printstr("\n");
        mx_printstr("========================================\n");
        temp = temp->parl;
    }
}

void mx_print_result(t_unit **result_matrix, int msize) {
    for (int i = 1; i < msize; i++) {
        for (int j = i; j < msize; j++) {
            // printf("i = %d j = %d\n", i, j);
            if ((result_matrix[i][j].isld == NULL &&
                result_matrix[i][j].dist == NULL) || i == j)
                continue;
            // printf("i = %d j = %d\n", i, j);
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
                mx_printstr(" = ");
                mx_printint(mx_count_dist(result_matrix[i][j].dist));
                mx_printstr("\n");
            }
            mx_printstr("========================================\n");
            if (result_matrix[i][j].parl != NULL) {
                // printf("i = %d j = %d\n", i, j);
                // printf("%s\n", result_matrix[i][j].isld);
                // printf("%s\n", result_matrix[i][j].parl->isld);
                // printf("print_list:\n\n\n");
                print_list(*result_matrix[i][j].parl, result_matrix[0][i].isld,
                result_matrix[0][j].isld);
                // ^^lmao bug fixed by costil
                // printf("print_listENC\n\n\n");
            }
        }
    }
}
