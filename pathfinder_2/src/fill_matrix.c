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

    for (i = 1; adj_matrix[i][0].isld != NULL; i++) {
        if (mx_strcmp(island, adj_matrix[i][0].isld) == 0) {
            return 1;
        }
        if (i == island_count) {
            mx_error_handler(INVALID_ISLANDS_COUNT, NULL, NULL);
            exit(-1);
            return -1;
        }
    }
    adj_matrix[i][0].isld = island;
    adj_matrix[0][i].isld = mx_strdup(island);
    adj_matrix[i][0].fifo = i;
    adj_matrix[0][i].fifo = i;
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

int mx_parse_line(t_unit **adj_matrix, char *line, int island_count) {
    // int i;
    char *island_i = mx_strdup_until_char(line, '-');
    char *island_j = mx_strdup_until_char(line + mx_strlen(island_i) + 1, ',');
    char *distance = mx_strdup_until_char(
    &line[mx_strlen(island_i) + mx_strlen(island_j) + 2], '\0');
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
    return 0;
}

int mx_fill_matrix(t_unit **adj_matrix, int island_count, char **file_str) {
    char *line = NULL;
    int i;

    mx_shift_str(*file_str, (mx_get_char_index(*file_str, '\n') + 1));
    for (i = 2; mx_get_char_index(*file_str, '\n') != -1; i++) { 
        line = mx_strjoin_until_char(&line, *file_str, '\n');
        mx_check_if_valid_line(line, i);
        if (mx_parse_line(adj_matrix, line, island_count) == -1)
           return -1; 
        mx_shift_str(*file_str, (mx_get_char_index(*file_str, '\n') + 1));
        mx_strdel(&line);
    } 
    if (**file_str != '\0') {
        mx_error_handler(INVALID_LINE, NULL, mx_itoa(i));
        exit(-1);
    }
    if (adj_matrix[0][island_count].isld == NULL) {
        printf("here\n");
        mx_error_handler(INVALID_ISLANDS_COUNT, NULL, NULL);
        exit(-1);
    }
    mx_loop_not_null(adj_matrix, island_count);
    mx_strdel(file_str);
    return 0;
}

