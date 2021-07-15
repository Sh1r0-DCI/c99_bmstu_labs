#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operating_funcs.h"
#include "strucs.h"


static int count_num_of_strucs(FILE *f)
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

static int get_struct_id(film_info *films, int num_of_films, // num of films = i in myio
                        char *arg_field, char *title, char *name, int year)
{
    if (!strcmp(arg_field, "year"))
    {
        for (int i = 0; i < num_of_films; i++)
        {
            if (year < films[i].year)
                return i;
        }
        
        return num_of_films;
    }
    else if (!strcmp(arg_field, "title"))
    {
        for (int i = 0; i < num_of_films; i++)
        {
            if (strcmp(title, films[i].title) < 0)
                return i;
        }
        
        return num_of_films;
    }
    else
    {
        for (int i = 0; i < num_of_films; i++)
        {
            if (strcmp(name, films[i].director_name) < 0)
                return i;
        }
        
        return num_of_films;
    }
}

int insert_struc(film_info *films, int num_of_films, char *field, 
                                    char *title, char *name, int year)
{
    int id = get_struct_id(films, num_of_films, field, title, name, year);

    for (int i = num_of_films; i > id; i--)
    {
        films[i].title = strdup(films[i - 1].title);
        free(films[i - 1].title);

        films[i].director_name = strdup(films[i - 1].director_name);
        free(films[i - 1].director_name);

        films[i].year = films[i - 1].year;
    }

    if(!(films[id].title = strdup(title)) ||
        !(films[id].director_name = strdup(name)))
        return ALLOC_ERROR;
    films[id].year = year;

    return OK;
}

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