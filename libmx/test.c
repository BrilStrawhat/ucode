typedef struct s_list {
    void *data;
    struct s_list *next;
}   t_list;

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);

int main(void) {
    t_list *node = mx_create_node("1");

    mx_push_front(&node, "2");
    mx_push_front(&node, "3");
    mx_push_front(&node, "4");
    mx_push_back(&node, "2");
}
