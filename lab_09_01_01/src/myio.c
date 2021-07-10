#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myio.h"


int input_strucs_from_file(FILE *f, film_info *films, int num_of_films)
{
    for (int i = 0; i < (num_of_films) && !feof(f); i++)
    {
        char *line = NULL;
        size_t len = 0;

    // _____________title_reading____________________
        if (getline(&line, &len, f) == -1)
        {
            return INPUT_ERROR;
        }

        // printf("\n%s\t\t\twas read\n", line);
        if (!(films[i].title = strdup(line)))
        {
            printf("input interrupt {title}\n");
            return ALLOC_ERROR;
        }

        printf("%s\t\t\t= %s\n", films[i].title, line);
        free(line);
    // -----------------------------------------------

        printf("title reading finished\n");

    // ____________director_name_reading______________
        printf("getline in shit started\n");
        if (getline(&line, &len, f) == -1)
        {
            return INPUT_ERROR;
        }
        printf("getline finished ok\n");

        // printf("%s\t\t\twas read\n", line);
        printf("strdup started\n");
        films[i].director_name = strdup(line);
        for (char *c = films[i].director_name; *c != '\0'; c++)
        {
            printf("\t\t%c\n", *c);
        }
        if (!(films[i].director_name))
        {
            printf("input interrupt {director name}\n");
            return ALLOC_ERROR;
        }
        printf("strdup finished\n");
            
        printf("%s\t\t\t= %s\n", films[i].director_name, line);
        free(line);
    // ------------------------------------------------

    printf("director name reading finished\n");

    // ________________year_reading____________________
        
        if (getline(&line, &len, f) == -1)
        {
            return INPUT_ERROR;
        }

        // printf("%s\t\t\twas read\n", line);
        films[i].year = (int) strtol(line, (char **)NULL, 10);
        printf("%d\t\t\t= %s\n", films[i].year, line);
        free(line);

        if (films[i].year < CINEMA_INVENTION_DATE)
        {
            printf("input interrupt {year}\n");
            return INCORECT_DATE;
        }
    // ------------------------------------------------
    }
        
    return OK;
}

void print_strucs_array(film_info *films, int num_of_films) 
{
    for (int i = 0; i < num_of_films; i++)
    {
        printf("\n%s\n%s\n%d\n", films[i].title, films[i].director_name, films[i].year);
    }
}