#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *result = mx_create_node(data);
    t_list *current = *list;

    if (*list == NULL)
        *list = result;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = result;
}
