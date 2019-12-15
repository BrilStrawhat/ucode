#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *result = mx_create_node(data);
    t_list *node = malloc(sizeof(t_list));

    for (node->next = **list; node->next != NULL;) {
        node = node->next;
        if (node->next == NULL)
            node->next = result;
    }
}
