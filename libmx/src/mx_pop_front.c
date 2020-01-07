#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *temp = *head;

    if (head == NULL || *head == NULL)
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    *head = (*head)->next;
    free(temp);
}
