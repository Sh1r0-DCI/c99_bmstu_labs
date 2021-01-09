#include <stdio.h>

#include "list_funcs.h"
#include "error_codes.h"

int push_back(node_t **head, char letter)
{
    if (*head == NULL)
    {
        *head = (node_t *)malloc(sizeof(node_t));
        (*head)->letter = letter;
        (*head)->next = NULL;
        
        return OK;
    }

    node_t *i = *head, *new_node;

    while (i->next != NULL)
    {
        i = i->next;
    }

    if (!(new_node = (node_t *)malloc(sizeof(node_t))))
    {
        return ALLOC_ERROR;
    }

    new_node->letter = letter;
    new_node->next = NULL;
    i->next = new_node;

    return OK;
}