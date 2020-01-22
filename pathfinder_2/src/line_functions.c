#include "pathfinder.h"

void mx_check_first_line(char *line, char **lineptr, char **file_str) {
    int i = 0;

    if (line[0] == '-')
        i++;
    for (; line[i] != '\0'; i++) {
        if (mx_isdigit(line[i]) == false) {
            mx_error_handler(INVALID_FIRST_LINE, NULL, NULL);
            mx_strdel(lineptr);
            mx_strdel(file_str);
            exit(-1);
        }
    }
    if (line[0] == '-') {
        mx_error_handler(INVALID_ISLANDS_COUNT, NULL, NULL);
        mx_strdel(lineptr);
        mx_strdel(file_str);
        exit(-1);
    }
}

static void costil_1(int argc, char **argv, char **lineptr, char **file_str) {
    int fd;

    if (argc != 2) {                                                           
        mx_error_handler(INVALID_ARGUMENTS_COUNT, NULL, NULL);                 
        exit(-1);                                                              
    }                                                                          
    fd = open(argv[1], O_RDONLY);                                             
    if (fd == -1) {                                                           
        mx_error_handler(FILE_DOES_NOT_EXISTS, argv[1], NULL);                 
        exit(-1);                                                              
    }                                                                          
    close(fd);
    *file_str = mx_file_to_str(argv[1]);
    if (mx_get_char_index(*file_str, '\n') == -1) {
        mx_error_handler(INVALID_FIRST_LINE, NULL, NULL);
        mx_strdel(file_str);
        exit(-1);
    }
    *lineptr = mx_strdup_until_char(*file_str, '\n');
}
//This is not me, this is Auditor^^

int mx_argv_argc_handler(int argc, char **argv, char **file_str) {                 
    int result;
    char *lineptr;
                                                                               
    costil_1(argc, argv, &lineptr, file_str);
    if (lineptr == NULL) {                         
        mx_error_handler(FILE_IS_EMPTY, argv[1], NULL);                        
        mx_strdel(file_str);
        exit(-1);                                                              
    }                                                                          
    mx_check_first_line(lineptr, &lineptr, file_str);
    result = mx_atoi(lineptr);
    mx_strdel(&lineptr);
    return result;                                                   
}                   
