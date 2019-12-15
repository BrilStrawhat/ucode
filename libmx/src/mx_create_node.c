#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *result = (t_list*)malloc(sizeof(t_list));

    if (!data)
        return NULL;
    result->data = data;
    result->next = NULL;
    return result;
}

