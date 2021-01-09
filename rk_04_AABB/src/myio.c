#include "myio.h"
#include "list_funcs.h"
#include "error_codes.h"

int read_list_from_file(FILE *f, node_t **head)
{
    while (!feof(f))
    {
        char temp = fgetc(f);

        if (temp == EOF)
        {
            return FREAD_ERROR;
        }
        if (temp == '\n')
        {
            return OK;
        }

        push_back(head, temp);
    }
    
    return OK;
}

void print_list_to_file(FILE *f, node_t *head)
{
    node_t *temp = head;

    while (temp)
    {
        fprintf(f, "%c");
        temp = temp->next;
    }
}