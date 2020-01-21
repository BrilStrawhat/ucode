#include "pathfinder.h"

void mx_prepare_result_matrix
(t_unit **adj_matrix, t_unit **result_matrix, int msize) {
    for (int i = 1; i < msize; i++)
        result_matrix[i][0].isld = mx_strdup(adj_matrix[i][0].isld);
    for (int i = 1; i < msize; i++)
        result_matrix[0][i].isld = mx_strdup(adj_matrix[0][i].isld);
}

// void mx_copy_col
// (t_unit **adj_matrix, t_unit **result_matrix, int msize, int s) {
    // for (int i = 0; i < msize; i++) {
        // if (adj_matrix[i][s].isld != NULL) {
            // free(result_matrix[i][s].isld);
            // result_matrix[i][s].isld = mx_strdup(adj_matrix[i][s].isld);
        // }
        // if (adj_matrix[i][s].dist != NULL) {
            // free(result_matrix[i][s].dist);
            // result_matrix[i][s].dist = mx_strdup(adj_matrix[i][s].dist);
        // }
    // }
// }


void mx_copy_row
(t_unit **adj_matrix, t_unit **result_matrix, int msize, int s) {
    for (int i = 0; i < msize; i++) {
        if (adj_matrix[s][i].isld != NULL) {
            free(result_matrix[s][i].isld);
            result_matrix[s][i].isld = mx_strdup(adj_matrix[s][i].isld);
        }
        if (adj_matrix[s][i].dist != NULL) {
            free(result_matrix[s][i].dist);
            result_matrix[s][i].dist = mx_strdup(adj_matrix[s][i].dist);
        }
        if (adj_matrix[s][i].parl != NULL) {
            result_matrix[s][i].parl = adj_matrix[s][i].parl;
        }
    }
}

void mx_add_distance(t_unit *result_matrix, char *distance) {
    char *plus = NULL;
    char *temp = result_matrix->dist;

    if (result_matrix->dist != NULL)
        plus = mx_strjoin(" + ", result_matrix->dist);
    result_matrix->dist = mx_strjoin(distance, plus);
    free(temp);
    free(plus);
}

void mx_add_island(t_unit *result_matrix, char *island) {
    char *arrow = NULL;
    char *temp = result_matrix->isld;

    if (result_matrix->isld != NULL)
        arrow = mx_strjoin(" -> ", result_matrix->isld);
    result_matrix->isld = mx_strjoin(island, arrow);
    free(temp);
    free(arrow);
}

void mx_copy_t_unit(t_unit *result_matrix, t_unit *adj_matrix) {
    char *temp_i = result_matrix->isld;
    char *temp_d = result_matrix->dist;

    if (adj_matrix->dist != NULL) {
        result_matrix->dist = mx_strdup(adj_matrix->dist);
        free(temp_d);
    }
    if (adj_matrix->isld != NULL) {
        result_matrix->isld = mx_strdup(adj_matrix->isld);
        free(temp_i);
    }
}

int mx_count_dist(char *dist) {
    int result = 0;

    for (int i = 0; dist[i] != '\0'; i++) {
        if (mx_isdigit(dist[i]) == true) {
            result += mx_atoi(&dist[i]);
            while (mx_isdigit(dist[i]) == true) {
                i++;
                if (dist[i] == '\0')
                    return result;;
            }
        }
    }
    return result;
}

int mx_floyd_cmp(t_unit *result_matrix, t_unit *adj_matrix_i,
t_unit *adj_matrix_j) {
    return mx_count_dist(result_matrix->dist) -
    (mx_count_dist(adj_matrix_i->dist) + mx_count_dist(adj_matrix_j->dist));
}

void mx_floyd_formula(
t_unit *result_matrix, t_unit *adj_matrix_j,
t_unit *adj_matrix_i, t_unit *step) {
    if (adj_matrix_i->dist == NULL || adj_matrix_j->dist == NULL) {
        return;
    }
    if (result_matrix->isld == NULL && result_matrix->dist == NULL) {
        mx_add_distance(result_matrix, adj_matrix_i->dist);
        mx_add_distance(result_matrix, adj_matrix_j->dist);
        if (adj_matrix_i->isld != NULL)
            mx_add_island(result_matrix, adj_matrix_i->isld);
        mx_add_island(result_matrix, step->isld);
        if (adj_matrix_j->isld != NULL)
            mx_add_island(result_matrix, adj_matrix_j->isld);
        // printf("result_matrix->isld == NULL && result_matrix->dist == NULL\n");
    }
    else {
        if (mx_floyd_cmp(result_matrix, adj_matrix_i, adj_matrix_j) < 0) {
            // printf("mx_floyd_cmp(result_matrix, adj_matrix_i, adj_matrix_j) < 0\n");
            return;
        }
        else if (mx_floyd_cmp(result_matrix, adj_matrix_i, adj_matrix_j) > 0) {
            // printf("mx_floyd_cmp(result_matrix, adj_matrix_i, adj_matrix_j) > 0\n");
            mx_strdel(&result_matrix->dist);
            mx_strdel(&result_matrix->isld);
            mx_add_distance(result_matrix, adj_matrix_i->dist);
            mx_add_distance(result_matrix, adj_matrix_j->dist);
            if (adj_matrix_i->isld != NULL)
                mx_add_island(result_matrix, adj_matrix_i->isld);
            mx_add_island(result_matrix, step->isld);
            if (adj_matrix_j->isld != NULL)
                mx_add_island(result_matrix, adj_matrix_j->isld);
        }
        else {
            // printf("mx_floyd_cmp(result_matrix, adj_matrix_i, adj_matrix_j) == 0\n");
            mx_push_back_t_unit(result_matrix,
            adj_matrix_j, adj_matrix_i, step->isld); 
        }
    }
}

void mx_swap_ptr_matrix(t_unit ***adj_matrix, t_unit ***result_matrix) {
    t_unit **buff = *adj_matrix;

    *adj_matrix = *result_matrix;
    *result_matrix = buff;
}

// void mx_go_list(t_unit **result_matrix, t_unit **temp_i, t_unit **temp_j,
void mx_floyd(t_unit **adj_matrix, t_unit **result_matrix, int msize) {
    int step = 0;
    t_unit *temp_i;
    t_unit *temp_j;

    while (step++ < msize - 1) {
        for (int k = 1; k < msize; k++)
            mx_copy_row(adj_matrix, result_matrix, msize, k); 
        for (int i = 1; i < msize; i++) {
            for (int j = 1; j < msize; j++) {
                if (i == step || j == step || i == j)
                    continue;
                if (adj_matrix[i][step].parl != NULL && adj_matrix[step][j].parl != NULL) {
                    temp_i = &adj_matrix[i][step];
                    while(temp_i != NULL) {
                        temp_j = &adj_matrix[step][j];
                        while (temp_j != NULL) {
                            mx_floyd_formula(&result_matrix[i][j], temp_i,
                            temp_j, &adj_matrix[0][step]);
                            temp_j = temp_j->parl;
                        }
                        temp_i = temp_i->parl;
                    }
                }
                else if (adj_matrix[i][step].parl != NULL && adj_matrix[step][j].parl == NULL) {
                    temp_i = &adj_matrix[i][step];
                    while(temp_i != NULL) {
                        mx_floyd_formula(&result_matrix[i][j], temp_i, &adj_matrix[step][j],
                        &adj_matrix[0][step]);
                        temp_i = temp_i->parl;
                    }
                    temp_i = &adj_matrix[i][step];
                }
                else if (adj_matrix[i][step].parl == NULL && adj_matrix[step][j].parl != NULL) {
                    temp_j = &adj_matrix[step][j];
                    while (temp_j != NULL) {
                        mx_floyd_formula(&result_matrix[i][j], &adj_matrix[i][step], temp_j,
                        &adj_matrix[0][step]);
                        temp_j = temp_j->parl;
                    }
                }
                else {
                    mx_floyd_formula(&result_matrix[i][j], &adj_matrix[i][step],
                    &adj_matrix[step][j], &adj_matrix[0][step]);
                }
            }
        }
        mx_swap_ptr_matrix(&adj_matrix, &result_matrix);
    }
    if (step % 2 != 0)
        mx_swap_ptr_matrix(&adj_matrix, &result_matrix);
}
int main(int argc, char **argv) {
    int fd;                                                                    
    int island_count = mx_argv_argc_handler(argc, argv, &fd); // need to add check if island_count < real_island_count
    int msize = island_count + 1;

    t_unit **adj_matrix = (t_unit**)malloc(msize * sizeof(t_unit*));
    t_unit **result_matrix = (t_unit**)malloc(msize * sizeof(t_unit*));
    mx_unit_malloc(adj_matrix, msize);
    mx_unit_malloc(result_matrix, msize);
    // if (mx_fill_matrix(adj_matrix, island_count, fd) == -1) {
        // mx_unit_free(adj_matrix, msize);
        // mx_unit_free(result_matrix, msize);
        // exit(-1);
    // }
    mx_fill_matrix(adj_matrix, island_count, argv[1]);
    mx_prepare_result_matrix(adj_matrix, result_matrix, msize);
    mx_floyd(adj_matrix, result_matrix, msize);
    // mx_print_parl(result_matrix, msize);
    // printf("FINISH result_matrix:\n");
    // mx_print_matrix(result_matrix, msize);
    // printf("adj_matrix:\n");
    // mx_print_matrix(adj_matrix, msize);
    // printf("\n");
    mx_print_result(result_matrix, msize);
    mx_unit_free(result_matrix, msize);
    mx_unit_free_n_list(adj_matrix, msize);
}
