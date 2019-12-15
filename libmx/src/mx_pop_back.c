#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *current = *head;

    if (head == NULL || *head == NULL)
        return;
    while (current->next->next != NULL) {
        // printf("fun %s\n", current->data);
        current = current->next;
    }
    mx_pop_front(&current->next);
}
