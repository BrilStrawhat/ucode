#include "pathfinder.h"

void mx_loop_not_null(t_unit **adj_matrix, int island_count) {
    while (island_count > 0) {
        if (adj_matrix[island_count][island_count].isld == NULL) 
            adj_matrix[island_count][island_count].isld = mx_strdup("0");
        island_count--;
    }
} // ^^ useless

int  mx_is_uniq_island
(t_unit **adj_matrix, char *island, int island_count) {
    int i;

    for (i = 1; adj_matrix[i][0].isld != NULL ; i++) {
        if (i > island_count) {
            mx_error_handler(INVALID_ISLANDS_COUNT, NULL, NULL);
            exit(-1);
        }
        if (mx_strcmp(island, adj_matrix[i][0].isld) == 0) {
            return 1;
        }
    }
    adj_matrix[i][0].isld = island;
    adj_matrix[0][i].isld = mx_strdup(island);
    return 0;
}

void mx_set_distance
(t_unit **adj_matrix, char *island_i, char *island_j, char *distance) {
    int i;
    int j;

    for (i = 1; adj_matrix[i][0].isld != NULL; i++) {
        if (mx_strcmp(adj_matrix[i][0].isld, island_i) == 0)
            break;
    }
    for (j = 1; adj_matrix[0][j].isld != NULL; j++) {
        if (mx_strcmp(adj_matrix[0][j].isld, island_j) == 0)
            break;
    }
    adj_matrix[i][j].dist = distance;
}

void mx_parse_line(t_unit **adj_matrix, char *line, int island_count) {
    char *island_i = mx_strdup_until_char(line, '-');
    char *island_j = mx_strdup_until_char(line + mx_strlen(island_i) + 1, ',');
    char *distance = mx_strdup_until_char(
    line + mx_strlen(island_i) + mx_strlen(island_i) + 2, '\0');
    int is_uniq[2] = { 0 };

    is_uniq[0] = mx_is_uniq_island(adj_matrix, island_i, island_count);
    is_uniq[1] = mx_is_uniq_island(adj_matrix, island_j, island_count);
    mx_set_distance(adj_matrix, island_i, island_j, distance);
    mx_set_distance(adj_matrix, island_j, island_i, mx_strdup(distance)); // could be an problem while free arr
    // ^^ could be leak if graph has loop
    if (is_uniq[0] == 1)
        mx_strdel(&island_i);
    if (is_uniq[1] == 1)
        mx_strdel(&island_j);
}

void mx_fill_matrix(t_unit **adj_matrix, int island_count, int fd) {
    char *line = NULL;
    int i;

    for (i = 2; mx_read_line(&line, 10, '\n', fd) != -1; i++) { 
        //^^Does not handle if mx_read_line return -2
        mx_check_if_valid_line(line, i);
        mx_parse_line(adj_matrix, line, island_count);
    } 
    mx_loop_not_null(adj_matrix, island_count);
}
