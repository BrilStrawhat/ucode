#include "pathfinder.h"

static void check_first_line(char *line) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (mx_isdigit(line[i]) == false) {
            mx_error_handler(INVALID_FIRST_LINE, NULL, NULL);
            exit(-1);
        }
    }
}

static int argv_argc_handler(int argc, char **argv, int *fd) {
    char *lineptr = NULL;

    if (argc != 2) {
        mx_error_handler(INVALID_ARGUMENTS_COUNT, NULL, NULL);
        exit(-1);
    }
    *fd = open(argv[1], O_RDONLY);
    if (*fd == -1) {
        mx_error_handler(FILE_DOES_NOT_EXISTS, argv[1], NULL);
        exit(-1);
    }
    if (mx_read_line(&lineptr, 10, '\n', *fd) == -1) {
        mx_error_handler(FILE_IS_EMPTY, argv[1], NULL);
        exit(-1);
    }
    check_first_line(lineptr);
    return mx_atoi(lineptr);
}

static void arr_malloc(char ***adj_matrix, int island_count) {
    for (int i = island_count; i >= 0; i--) {
        adj_matrix[i] = malloc(island_count * sizeof(char *));
    }
}

static void is_uniq_island
(char ***adj_matrix, char *island, int island_count) {
    int i;

    for (i = 1; adj_matrix[i][0] != NULL ; i++) {
        if (i > island_count) {
            mx_error_handler(INVALID_ISLANDS_COUNT, NULL, NULL);
            exit(-1);
        }
        if (mx_strcmp(island, adj_matrix[i][0]) == 0)
                return;
    }
    adj_matrix[i][0] = island;
    adj_matrix[0][i] = island;
}

static void set_distance
(char ***adj_matrix, char *island_i, char *island_j, char *distance) {
    int i;
    int j;

    for (i = 1; adj_matrix[i][0] != NULL; i++) {
        if (mx_strcmp(adj_matrix[i][0], island_i) == 0)
            break;
    }
    for (j = 1; adj_matrix[0][j] != NULL; j++) {
        if (mx_strcmp(adj_matrix[j][0], island_j) == 0)
            break;
    }
    adj_matrix[i][j] = distance;
}

static void parse_line(char ***adj_matrix, char *line, int island_count) {
    char *island_i = mx_strdup_until_char(line, '-');
    char *island_j = mx_strdup_until_char(line + mx_strlen(island_i) + 1, ',');
    char *distance = mx_strdup_until_char(
    line + mx_strlen(island_i) + mx_strlen(island_i) + 2, '\0');

    is_uniq_island(adj_matrix, island_i, island_count);
    is_uniq_island(adj_matrix, island_j, island_count);
    set_distance(adj_matrix, island_i, island_j, distance);
    set_distance(adj_matrix, island_j, island_i, distance); // could be an problem while free arr
    // ^^ could be leak if graph has loop
    // mx_strdel(&island_i);
    // mx_strdel(&island_j);
    // mx_strdel(&distance);
}

static void check_if_valid_line(char *line, int line_number) {
    int i;

    for (i = 0; line[i] != '-'; i++) {
        if (mx_isalpha(line[i]) == false) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(line_number));
            exit(-1);
        }
    }
    for (i = i + 1; line[i] != ','; i++) {
        if (mx_isalpha(line[i]) == false) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(line_number));
            exit(-1);
        }
    }
    for (i = i + 1; line[i] != '\0'; i++) {
        if (mx_isdigit(line[i]) == false) {
            mx_error_handler(INVALID_LINE, NULL, mx_itoa(line_number));
            exit(-1);
        }
    }
}    

static void loop_nut_null(char ***adj_matrix, int island_count) {
    while (island_count >= 0) {
        if (adj_matrix[island_count][island_count] == NULL) 
            adj_matrix[island_count][island_count] = mx_strdup("0");
        island_count--;
    }
}

static void fill_matrix(char ***adj_matrix, int island_count, int fd) {
    char *line = NULL;
    int i;

    for (i = 2; mx_read_line(&line, 10, '\n', fd) != -1; i++) { 
        //^^Does not handle if mx_read_line return -2
        check_if_valid_line(line, i);
        parse_line(adj_matrix, line, island_count);
    } 
    loop_nut_null(adj_matrix, island_count);
}

static bool is_direct_path(char *path) {
    for (int i = 0; path[i] != '\0'; i++) {
        if (mx_isdigit(path[i]) == false)
            return false;
    }
    return true;
}

static void floyd_formula
(char ***result_matrix, char ***adj_matrix, int ij[2], int step) {
    if (adj_matrix[ij[0]][ij[1]] = NULL) {
        // adj_matrix[ij[0]][ij[1]] = mx_strdup("Path: \nRoute: \nDistance: \n");


}

static void floyd
(char ***adj_matrix, char ***result_matrix, int island_count) {
    int step = 1;
    int ij[2] = {2, 3};

    while (step++ <= island_count) {
        for (int i = 1; i <= island_count; i++) {
            for (int j = 1; j <= island_count; j++) {
                if (adj_matrix[i][j] != NULL)
                    if (is_direct_path(adj_matrix[i][j]) == true)
                            continue;
                ij[0] = i;
                ij[1] = j;
                floyd_formula(result_matrix, adj_matrix, ij, step);
            }
        }
    }
}

int main(int argc, char **argv) {
    // char **adj_matrix =  NULL; mx_read_line bug
    // char *line = NULL;
    int fd;
    int island_count = argv_argc_handler(argc, argv, &fd);
    char ***adj_matrix = malloc((island_count + 1) * sizeof(char **)); // fill last COL and ROW '\0'
    char ***result_matrix = malloc((island_count + 1) * sizeof(char **)); // fill last COL and ROW '\0'
    // char *island_i;
    // char *island_j;

    arr_malloc(adj_matrix, island_count + 1);
    arr_malloc(result_matrix, island_count + 1);
    fill_matrix(adj_matrix, island_count, fd);
    floyd(adj_matrix, result_matrix, island_count);
    for (int i = 0; i <= island_count; i++) {
        for (int j = 0; j <= island_count; j++) {
            if (adj_matrix[i][j] == NULL) {
                printf("|-|");
                continue;
            }
            printf("|%s|", adj_matrix[i][j]);
        }
        printf("\n");
    }
    close(fd);
}
