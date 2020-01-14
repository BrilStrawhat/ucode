#include "pathfinder.h"

static void free_t_unit_list(t_unit* head) {
   t_unit* tmp;

   while (head != NULL) {
       tmp = head;
       head = head->parl;
       free(tmp);
    }
}

// void mx_push_back_t_unit
// (t_unit **list, char *isld_i, char *isld_j char *dist) {
    // t_unit *result = (t_unit*)malloc(sizeof(t_unit));
    // t_unit *current = *list;

    // mx_add_island(result, isld_i);
    // mx_add_island(result, isld_j);
    // mx_add_distance(result, dist);
    // result->parl = NULL;
    // if (*list == NULL) {
        // *list = result;
        // return;
    // }
    // while (current->parl != NULL) {
        // current = current->parl;
    // }
    // current->parl = result;
// }

void mx_unit_malloc(t_unit **matrix, int island_count) {
    for (int i = 0; i < island_count; i++)
        matrix[i] = (t_unit*)malloc(island_count * sizeof(t_unit));
    for (int i = 0; i < island_count; i++) {
        for (int j = 0; j < island_count; j++) {
            matrix[i][j].isld = NULL;
            matrix[i][j].dist = NULL;
            matrix[i][j].parl = NULL;
        }
    }
}

void mx_unit_free(t_unit **matrix, int island_count) {
    for (int i = 0; i < island_count; i++) {
        for (int j = 0; j < island_count; j++) {
            free(matrix[i][j].isld);
            free(matrix[i][j].dist);
            free_t_unit_list(matrix[i][j].parl);
        }
    }
    for (int i = 0; i < island_count; i++)
        free(matrix[i]);
    free(matrix);
}
