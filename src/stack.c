#include "../lib/elepemon.h"

int is_empty(struct elepemon_node* stack)
{
    return stack == NULL;
}

struct elepemon* get_elepemon( struct elepemon_node* stack, const char* name)
{
    struct elepemon_node* ptr = stack;

    while( !(is_empty (ptr)) ){
        if ( !strcmp(ptr -> elepemon.name,name) ){
            return &(ptr->elepemon);
        }
        ptr = ptr -> next;
    }

    return NULL;
}

void free_elepemon_stack(struct elepemon_node* stack)
{
    struct elepemon_node* aux;
    while( !(is_empty(stack)) ){
        free_elepemon(&(stack->elepemon));
        aux = stack;
        stack = stack-> next;
        free(aux);
    }

}

void recorrer(struct elepemon_node* stack)
{
    struct elepemon_node* ptr = stack;
    if (ptr == NULL) {
        printf("vacio\n");
        return;
    }
    while( !( is_empty(ptr) ) ){
        print_elepemon( &(ptr->elepemon) ); printf("----------------\n");
        ptr = ptr->next;
    }
}

struct elepemon_node* push_elepemon(struct elepemon_node** stack, const char* name)
{
    struct elepemon_node* aux;
    aux = *stack;

    *stack = malloc(sizeof(struct elepemon_node));
    init_elepemon(&((*stack)->elepemon));
    (*stack)->elepemon.name = strdup(name);
    (*stack)->next = aux;

    return *stack;
}
