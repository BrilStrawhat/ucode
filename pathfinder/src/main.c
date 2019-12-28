#include "pathfinder.h"

static int argv_argc_handler(int argc, char **argv) {
    int fd;
    char *lineptr = NULL;

    if (argc != 2) {
        mx_error_handler(INVALID_ARGUMENTS_COUNT, NULL, NULL);
        exit(-1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        mx_error_handler(FILE_DOES_NOT_EXISTS, argv[1], NULL);
        exit(-1);
    }
    if (mx_read_line(&lineptr, 10, '\n', fd) == -1) {
        mx_error_handler(FILE_IS_EMPTY, argv[1], NULL);
        exit(-1);
    }
    // add check for valid first line
    return mx_atoi(lineptr);
}

// static void fill_matrix(char **argv, char **adj_matrix, int fd) {
    // printf("%s\n" , 
    
// }
int main(int argc, char **argv) {
    // char **adj_matrix =  NULL; read_line bug
    // char ***adj_matrix = NULL;
    int fd = open(argv[1], O_RDONLY);
    int islend_count = argv_argc_handler(argc, argv);
    char *adj_matrix[islend_count][islend_count]; // fill last COL and ROW '\0'
    mx_set_arr_null(islend_count, islend_count, adj_matrix);
    printf("%d\n", mx_read_line(&adj_matrix[0][0], 10, '\n', fd));
    // printf("%s\n", adj_matrix[0][0]);
    // argc = 1;
    // argv = NULL;
    close(fd);
}
