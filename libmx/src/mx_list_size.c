#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *current = list;
    int result = 0;

    if (list == NULL)
        return 0;
    while (current != NULL) {
        current = current->next;
        result++;
    }
    return result;
}
