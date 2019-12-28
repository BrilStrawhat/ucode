#ifndef LIBMX_H_
#define LIBMX_H_

#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
// #include <malloc/malloc.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}   t_list;

void mx_print_unicode(wchar_t c);
void mx_print_strarr(char **arr, const char *delim);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printchar(char c);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
void mx_foreach(const int *arr, int size, void (*f)(int));
int mx_strcmp(const char*s1, const char*s2);
int mx_binary_search(char** arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);


void mx_str_reverse(char *s);
void mx_swap_char(char *s1, char *s2);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char* str, char c);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcat(char *s1, const char *s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char delimiter);
bool mx_isspace(int c);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strdup_until_char(const char *s1, char  delim);
char *mx_strtrim_char(const char *s1, char c);
char *mx_itoa(int number);
char *mx_file_to_str(const char *file);
int mx_read_line(char** lineptr, size_t buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
unsigned int mx_abs(int num);
char *mx_strnreplace(char *dst, const char *src, int len);

void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src,
                 int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len,
                const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
char *mx_strcat_until_char(char *s1, const char *s2, char delim);
char *mx_strjoin_until_char(char **s1, const char *s2, char delim);
char *mx_strjoin(const char *s1, const char *s2);
void mx_iarr_rotate(int *arr, int size, int shift);
void mx_shift_str(char *str, int shift);
void *mx_realloc(void *ptr, size_t size);
char *mx_strcpy_until_char(char *dst, const char *src, char delim);
void mx_print_error(const char *error);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
//list functions:
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);

#endif
