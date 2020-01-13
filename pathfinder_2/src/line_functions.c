#include "pathfinder.h"

void mx_check_first_line(char *line) {
    for (int i = 0; line[i] != '\0'; i++) {
        if (mx_isdigit(line[i]) == false) {
            mx_error_handler(INVALID_FIRST_LINE, NULL, NULL);
            exit(-1);
        }
    }
}

int mx_argv_argc_handler(int argc, char **argv, int *fd) {                 
    char *lineptr = NULL;                                                      
    int result;
                                                                               
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
    mx_check_first_line(lineptr);                                                 
    result = mx_atoi(lineptr);
    mx_strdel(&lineptr);
    return result;                                                   
}                   
