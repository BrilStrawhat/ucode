#include "pathfinder.h"

void mx_free_t_unit_list(t_unit **head) {
   t_unit *tmp;

   while (*head != NULL) {
       tmp = *head;
       *head = (*head)->parl;
       free(tmp->isld);
       free(tmp->dist);
       free(tmp);
    }
   *head = NULL;
}

void mx_push_back_t_unit
(t_unit *result_matrix, t_unit *adj_matrix_j,
t_unit *adj_matrix_i, char *island) {
    t_unit *result = (t_unit*)malloc(sizeof(t_unit));
    t_unit *current = result_matrix;

    result->isld = NULL;
    result->dist = NULL;
    result->parl = NULL;
    if (adj_matrix_i->isld != NULL)
        mx_add_island(result, adj_matrix_i->isld);
    mx_add_island(result, island);
    if (adj_matrix_j->isld != NULL)
        mx_add_island(result, adj_matrix_j->isld);
    mx_add_distance(result, adj_matrix_i->dist);
    mx_add_distance(result, adj_matrix_j->dist);
    if (result_matrix->parl == NULL) {
        result_matrix->parl = result;
        return;
    }
    // while (current->parl != NULL) {
        // current = current->parl;
    // }
    // current->parl = result;
    result->parl = result_matrix->parl;
    result_matrix->parl = result;
}

t_unit **mx_unit_malloc(t_unit **matrix, int island_count) {
    matrix = (t_unit**)malloc((island_count + 1) * sizeof(t_unit*));
    for (int i = 0; i < island_count; i++)
        matrix[i] = (t_unit*)malloc(island_count * sizeof(t_unit));
    for (int i = 0; i < island_count; i++) {
        for (int j = 0; j < island_count; j++) {
            matrix[i][j].isld = NULL;
            matrix[i][j].dist = NULL;
            matrix[i][j].parl = NULL;
        }
    }
    return matrix;
}

void mx_unit_free(t_unit **matrix, int island_count) {
    for (int i = 0; i < island_count; i++) {
        for (int j = 0; j < island_count; j++) {
                free(matrix[i][j].isld);
                free(matrix[i][j].dist);
            if (matrix[i][j].parl != NULL)
                mx_free_t_unit_list(&matrix[i][j].parl);
            // else
                // free(matrix[i][j].parl);
        }
    }
    for (int i = 0; i < island_count; i++)
        free(matrix[i]);
    free(matrix);
}

void mx_unit_free_n_list(t_unit **matrix, int island_count) {
    for (int i = 0; i < island_count; i++) {
        for (int j = 0; j < island_count; j++) {
                free(matrix[i][j].isld);
                free(matrix[i][j].dist);
        }
    }
    for (int i = 0; i < island_count; i++)
        free(matrix[i]);
    free(matrix);
}
