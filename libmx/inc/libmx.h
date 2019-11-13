#ifndef LIBMX_H_
#define LIBMX_H_

#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
char *strstr(const char *haystack, const char *needle);

#endif