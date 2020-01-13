#include "pathfinder.h"

void mx_prepare_result_matrix
(t_unit **adj_matrix, t_unit **result_matrix, int msize) {
    for (int i = 1; i < msize; i++)
        result_matrix[i][0].isld = mx_strdup(adj_matrix[i][0].isld);
    for (int i = 1; i < msize; i++)
        result_matrix[0][i].isld = mx_strdup(adj_matrix[0][i].isld);
}

void mx_copy_static_col_row
(t_unit **adj_matrix, t_unit **result_matrix, int msize, int s) {
    for (int i = 0; i < msize; i++) {
        if (adj_matrix[i][s].isld != NULL) {
            free(result_matrix[i][s].isld);
            result_matrix[i][s].isld = mx_strdup(adj_matrix[i][s].isld);
        }
        if (adj_matrix[i][s].dist != NULL) {
            free(result_matrix[i][s].dist);
            result_matrix[i][s].dist = mx_strdup(adj_matrix[i][s].dist);
        }
    }
    for (int i = 0; i < msize; i++) {
        if (adj_matrix[s][i].isld != NULL) {
            free(result_matrix[s][i].isld);
            result_matrix[s][i].isld = mx_strdup(adj_matrix[s][i].isld);
        }
        if (adj_matrix[s][i].dist != NULL) {
            free(result_matrix[s][i].dist);
            result_matrix[s][i].dist = mx_strdup(adj_matrix[s][i].dist);
        }
    }
}

void mx_copy_col
(t_unit **adj_matrix, t_unit **result_matrix, int msize, int s) {
    for (int i = 0; i < msize; i++) {
        if (adj_matrix[i][s].isld != NULL) {
            free(result_matrix[i][s].isld);
            result_matrix[i][s].isld = mx_strdup(adj_matrix[i][s].isld);
        }
        if (adj_matrix[i][s].dist != NULL) {
            free(result_matrix[i][s].dist);
            result_matrix[i][s].dist = mx_strdup(adj_matrix[i][s].dist);
        }
    }
}

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
    }
}

void mx_add_distance(t_unit *result_matrix, char *distance) {
    char *plus = NULL;
    char *temp = result_matrix->dist;

    if (result_matrix->dist != NULL)
        plus = mx_strjoin(" + ", result_matrix->dist);
    else
        plus = mx_strdup(" + ");
    result_matrix->dist = mx_strjoin(distance, plus);
    free(temp);
    free(plus);
}

void mx_add_island(t_unit *result_matrix, char *island) {
    char *arrow = NULL;
    char *temp = result_matrix->isld;

    if (result_matrix->isld != NULL)
        arrow = mx_strjoin(result_matrix->isld, " -> ");
    else
        arrow = mx_strdup(" -> ");
    result_matrix->isld = mx_strjoin(island, arrow);
    free(temp);
    free(arrow);
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
t_unit *result_matrix, t_unit *adj_matrix_i,
t_unit *adj_matrix_j, char *island) {
    if (adj_matrix_i->dist == NULL || adj_matrix_j->dist == NULL)
        return;
    if (result_matrix->isld == NULL && result_matrix->dist == NULL) {
        mx_add_distance(result_matrix, adj_matrix_i->dist);
        mx_add_distance(result_matrix, adj_matrix_j->dist);
        mx_add_island(result_matrix, island);
    }
    else {
        // printf("floyd_formuld else res->dis = %s\nadj_i-dest = %s\nadj_j = %s\n",
        // result_matrix->dist, adj_matrix_i->dist, adj_matrix_j->dist);
        if (mx_floyd_cmp(result_matrix, adj_matrix_i, adj_matrix_j) < 0)
            return;
        if (mx_floyd_cmp(result_matrix, adj_matrix_i, adj_matrix_j) = 0) {


        }
        // mx_add_distance(result_matrix, adj_matrix_i->dist);
        // mx_add_distance(result_matrix, adj_matrix_j->dist);
        // mx_add_island(result_matrix, adj_matrix_i->isld);
        // mx_add_island(result_matrix, adj_matrix_i->isld);
        // mx_add_island(result_matrix, island);
    }
}

void mx_swap_ptr_matrix(t_unit ***adj_matrix, t_unit ***result_matrix) {
    t_unit **buff = *adj_matrix;

    *adj_matrix = *result_matrix;
    *result_matrix = buff;
}

void mx_floyd(t_unit **adj_matrix, t_unit **result_matrix, int msize) {
    int step = 0;
    int curr = 1;   

    while (step++ < msize) {
        curr = (curr == 1) ? 0 : 1;
        if (curr == 1) {
            mx_swap_ptr_matrix(&adj_matrix, &result_matrix);
            printf("matrix swaped\n");
        }
        // printf("before forfor res_mat:\n");
        // mx_print_matrix(result_matrix, msize);
        // printf("adj_mat:\n");
        // mx_print_matrix(adj_matrix, msize);
        // printf("\n");
        mx_copy_static_col_row(adj_matrix, result_matrix, msize, step);
        // mx_print_matrix(result_matrix, msize);
        // printf("\n");
        // mx_print_matrix(adj_matrix, msize);
        // printf("\n");
        for (int i = 1; i < msize; i++) {
            for (int j = 1; j < msize; j++) {
                if (i == j)
                    continue;
                if (i == step || j == step) {
                    if (adj_matrix[i][step].dist == NULL && i != step) {
                        mx_copy_row(adj_matrix, result_matrix, msize, i);
                    }
                    else if (adj_matrix[step][j].dist == NULL && j != step) {
                        mx_copy_col(adj_matrix, result_matrix, msize, j);
                    }
                    continue;
                }
                // printf("floyd\n");
                // mx_print_matrix(result_matrix, msize);
                // printf("i = %d j = %d\n", i, j);
                mx_floyd_formula(&result_matrix[i][j], &adj_matrix[i][step],
                &adj_matrix[step][j], adj_matrix[0][step].isld);
            }
        }
        printf("end for for\n");
        if (step == 2)
            break;
    }
}
// strcpm(&result_matrix.isld[i], " -> \0");
int main(int argc, char **argv) {
    int fd;                                                                    
    int island_count = mx_argv_argc_handler(argc, argv, &fd); // need to add check if island_count < real_island_count
    int msize = island_count + 1;

    t_unit **adj_matrix = (t_unit**)malloc(msize * sizeof(t_unit*));
    t_unit **result_matrix = (t_unit**)malloc(msize * sizeof(t_unit*));
    mx_unit_malloc(adj_matrix, msize);
    mx_unit_malloc(result_matrix, msize);
    mx_fill_matrix(adj_matrix, island_count, fd);
    mx_prepare_result_matrix(adj_matrix, result_matrix, msize);
    mx_floyd(adj_matrix, result_matrix, msize);
    printf("FINISH result_matrix:\n");
    mx_print_matrix(result_matrix, msize);
    printf("adj_matrix:\n");
    mx_print_matrix(adj_matrix, msize);
    printf("\n");
    mx_unit_free(adj_matrix, msize);
    mx_unit_free(result_matrix, msize);
}
