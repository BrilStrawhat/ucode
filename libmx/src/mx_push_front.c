#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *result = mx_create_node(data);

    result->next = *list;
    *list = result;
}
