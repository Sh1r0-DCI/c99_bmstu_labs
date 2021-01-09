#include <stdio.h>
#include <stdlib.h>

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

void reverse(node_t **head)
{
    node_t *i = *head, *prev_word = *head, *temp = NULL, \
    *last_space = NULL;

    while (i)
    {
        if (i->letter == ' ')
        {
            last_space = i;
            temp = i->next;
            i->next = prev_word;
            prev_word = temp;

            i = temp;
        }
        // else if (i->next == NULL)
        // {
        //     i->next = last_space;
        // }
        else
        {
            i = i->next;
        }
    }

    *head = prev_word;
    (*head)->next = last_space;
}

void free_list(node_t **head)
{
    if (!((*head)->next))
    {
        free(*(head));
    }
    else
    {
        free_list(&((*head)->next));
    }
}