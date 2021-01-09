#include "myio.h"
#include "list_funcs.h"
#include "error_codes.h"

int read_list_from_file(FILE *f, node_t **head)
{
    int rc = OK;
    char temp = fgetc(f);

    while (!feof(f) && temp != EOF)
    {
        if (temp == EOF)
        {
            return FREAD_ERROR;
        }
        if (temp == '\n')
        {
            return OK;
        }

        if((rc = push_back(head, temp)))
        {
            return rc;
        }

        temp = fgetc(f);
    }
    
    return OK;
}

void print_list_to_file(FILE *f, node_t *head)
{
    node_t *temp = head;

    while (temp)
    {
        //fprintf(f, "%s", temp);
        fputc(temp->letter, f);
        temp = temp->next;
    }
}