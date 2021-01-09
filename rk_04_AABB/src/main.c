#include <stdio.h>

#include "error_codes.h"
#include "myio.h"
#include "list_funcs.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return WRONG_ARGS;
    }

    FILE *f_in = NULL, *f_out = NULL;

    if (!(f_in = fopen(argv[1], "r")) || !(f_out = fopen("out.txt", "w")))
    {
        return FOPEN_ERROR;
    }

    node_t *head = NULL;
    int rc = OK;

    if ((rc = read_list_from_file(f_in, &head)))
    {
        return rc;
    }

    reverse(&head);

    print_list_to_file(f_out, head);

    free_list(&head);
    return OK;
}