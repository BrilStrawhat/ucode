#ifndef PATHFINDER_H                                                           
#define PATHFINDER_H                                                           
                                                                               
#include "libmx.h"                                                             
#include "stdio.h"                                                             
                                                                               
// Enums                                                                       
typedef enum e_error {                                                         
    INVALID_ARGUMENTS_COUNT,                                                   
    FILE_DOES_NOT_EXISTS,                                                      
    FILE_IS_EMPTY,                                                             
    INVALID_FIRST_LINE,                                                        
    INVALID_LINE,                                                              
    INVALID_ISLANDS_COUNT                                                      
} t_error;                                                                     

typedef struct s_unit {
    char *isld;
    char *dist;
    int fifo;
    struct s_unit *parl;
} t_unit;

// errors function
void mx_three_to_one(char *first_part, char *text, char *second_part);         
void mx_error_handler(t_error error, char *filename, char *text);              
void mx_check_if_valid_line(char *line, int line_number);
void mx_check_first_line(char *line, char **lineptr, char **file_str);
// memory_function
t_unit **mx_unit_malloc(t_unit **matrix, int island_count);
void mx_unit_free(t_unit **matrix, int island_count);
void mx_push_back_t_unit
(t_unit *result_matrix, t_unit *adj_matrix_j,
t_unit *adj_matrix_i, char *island);
void mx_free_t_unit_list(t_unit **head);
void mx_unit_free_n_list(t_unit **matrix, int island_count);
// fill_matrix functions
void mx_loop_not_null(t_unit **adj_matrix, int island_count);
int  mx_is_uniq_island
(t_unit **adj_matrix, char *island, int island_count);
void mx_set_distance
(t_unit **adj_matrix, char *island_i, char *island_j, char *distance);
int mx_parse_line(t_unit **adj_matrix, char *line, int island_count);
int mx_fill_matrix(t_unit **adj_matrix, int island_count, char **file_str);
// print_function
void mx_print_matrix(t_unit **adj_matrix, int msize);
void mx_print_result(t_unit **result_matrix, int msize);
void mx_add_island(t_unit *result_matrix, char *island);
void mx_print_parl(t_unit **result_matrix, int msize);

// floyd_function
int mx_count_dist(char *dist); 
void mx_add_distance(t_unit *result_matrix, char *distance);

int mx_argv_argc_handler(int argc, char **argv, char **file_str);
#endif      
