#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parse_args.h"
#include "strucs.h"

int parse_args(const int argc, const char *argv[], char *file_name, char **field, char **key)
{   // app.exe FILE FIELD{title/name/year} [KEY]
    if (argc < 3 || argc > 4)
        return ARGS_ERROR;

    if (strcmp(argv[2], "title") & strcmp(argv[2], "name") & strcmp(argv[2], "year"))
        return ARGS_ERROR;

    strcpy(file_name, argv[1]);
    *field = (char *) malloc(strlen(argv[2]) + 1);

    if (*field == NULL)
        return ALLOC_ERROR;

    strcpy(*field, argv[2]);

    if (argc == 4)
    {
        *key = malloc(strlen(argv[3]) + 2);

        if (key == NULL)
            return ALLOC_ERROR;

        strcpy(*key, argv[3]);
        strcat(*key, "\n");
    }

    return OK;
}