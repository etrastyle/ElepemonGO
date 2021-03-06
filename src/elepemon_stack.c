#include <elepemon.h>

int is_empty(struct elepemon_node* stack)
{
    return stack == NULL;
}

struct elepemon* get_elepemon(struct elepemon_node* stack, const char* name)
{
    struct elepemon_node* ptr = stack;

    while (!(is_empty(ptr))) {
        if (!strcmp(ptr->elepemon.name, name)) {
            return &(ptr->elepemon);
        }
        ptr = ptr->next;
    }

    return NULL;
}

void free_elepemon_stack(struct elepemon_node* stack)
{
    struct elepemon_node* aux;
    while (!(is_empty(stack))) {
        free_elepemon(&(stack->elepemon));
        aux = stack;
        stack = stack->next;
        free(aux);
    }

}

void print_stack(struct elepemon_node* stack)
{
    int i = 1;
    struct elepemon_node *ptr = stack;
    if (ptr == NULL) {
        printf("vacio\n");
        return;
    }
    while (!(is_empty(ptr))) {
        printf("%d.-\n", i++);
        print_elepemon(&ptr->elepemon);
        printf("\n");
        ptr = ptr->next;
    }
}

struct elepemon_node* push_elepemon(struct elepemon_node** stack, const char* name)
{
    struct elepemon_node* aux;
    aux = malloc(sizeof(struct elepemon_node));
    init_elepemon(&(aux->elepemon));
    aux->elepemon.name = strdup(name);
    aux->next = *stack;
    *stack = aux;
    return *stack;
}

void move_stack_node(struct elepemon_node** from, struct elepemon_node** to, int indice)
{
    struct elepemon_node *aux = *from;
    struct elepemon_node *to_move;
    if (indice == 1) {
        (*from) = (*from)->next;
        aux->next = *to;
        *to = aux;
        return;
    }

    indice -= 2;
    while (indice--) {
        aux = aux->next;
    }
    to_move = aux->next;
    aux->next = aux->next->next;

    to_move->next = *to;
    *to = to_move;

    return;
}

int find_index(struct elepemon_node *stack, struct elepemon *elepemon)
{
    int i = 0;
    while(stack != NULL) {
        i++;
        if (&(stack->elepemon) == elepemon)
            return i;
        stack = stack->next;
    }
    return 0;
}

int get_stack_size(struct elepemon_node *stack)
{
    int i = 0;
    while (!is_empty(stack)) {
        stack = stack->next;
        i++;
    }

    return i;
}
