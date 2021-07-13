#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operating_funcs.h"
#include "strucs.h"


static int count_num_of_strucs(FILE *f) // decided to use getline + sscanf (realloc/malloc ???)
{
    int n = 0;

    char *line = NULL;
    size_t len = 0;

    for (; getline(&line, &len, f) != -1; n++);

    rewind(f);
    free(line);

    if (n % 3 != 0)
        return -1;

    return n/3;
}

// int insert_struc(film_info *films, int num_of_films, )

int alloc_struc_array(FILE *f, film_info **p_films, int *p_num_of_films)
{
    if (f == NULL)
        return UNEXISTING_FILE;

    *p_num_of_films = count_num_of_strucs(f);
    if (*p_num_of_films == -1)
        return FILE_INF_ERROR;

    *p_films = (film_info*) malloc(*p_num_of_films * sizeof(film_info));
    if (*p_films == NULL)
        return ALLOC_ERROR;

    return OK;
}

void free_array(film_info *films, int num_of_films)
{
    for (int i = 0; i < num_of_films; i++)
    {
        free(films[i].title);
        free(films[i].director_name);
    }
    
    free(films);
}