#include "libmx.h"

// void mx_push_front(t_list **list, void *data) {
//     t_list *result = mx_create_node(data);

//     result->next = *list;
//     *list = result;
// }

void mx_push_front(t_list **list, void *data)
{
    t_list *front_list = mx_create_node(data);
    
    if (list == NULL || *list == NULL)
    {
        *list = front_list;
    }
    else
    {
        t_list *temp = NULL;

        temp = *list;
        *list = front_list;
        front_list->next = temp;
    }
}
