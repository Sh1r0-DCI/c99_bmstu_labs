#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include "myio.h"


int input_strucs_from_file(FILE *f, film_info *films, int num_of_films) // strucs are instantly sorted
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
    // -----------------------------------------------

        // printf("title reading finished\n");

    // ____________director_name_reading______________
        if (getline(&line, &len, f) == -1)
        {
            return INPUT_ERROR;
        }

        // printf("%s\t\t\twas read\n", line);
        films[i].director_name = strdup(line);

        if (!(films[i].director_name))
        {
            printf("input interrupt {director name}\n");
            return ALLOC_ERROR;
        }
        // printf("%s\t\t\t= %s\n", films[i].director_name, line);
    // ------------------------------------------------

        // printf("director name reading finished\n");

    // ________________year_reading____________________
        
        if (getline(&line, &len, f) == -1)
        {
            return INPUT_ERROR;
        }

        // printf("%s\t\t\twas read\n", line);
        films[i].year = (int) strtol(line, (char **)NULL, 10);
        // printf("%d\t\t\t= %s\n", films[i].year, line);

        if (films[i].year < CINEMA_INVENTION_DATE)
        {
            printf("input interrupt {year}\n");
            return INCORECT_DATE;
        }
    // ------------------------------------------------

        free(line);
    }
        
    return OK;
}

void print_strucs_array(film_info *films, int num_of_films) 
{
    int answer = -1;

    sleep(5);
    printf("num of films is %d\n", num_of_films);

    if (num_of_films > 20)
    {
        printf("Too much films. Still print them all?\n");
        printf("Answer(0 - No, 1 - Yes): ");
        fflush(stdout);

        int rc = scanf("%d", &answer);

        if(rc != 1)
        {
            print_strucs_array(films, num_of_films);
            return;
        }

        if (!answer)
        {
            printf("\n%s%s%d\n", films[0].title, films[0].director_name, films[0].year);
            printf("\n...\n...\n...\n");
            printf("\n%s%s%d\n", films[num_of_films - 1].title, 
                    films[num_of_films - 1].director_name, films[num_of_films - 1].year);
            return;
        }
    }

    for (int i = 0; i < num_of_films; i++)
    {
        printf("\n%s%s%d\n", films[i].title, films[i].director_name, films[i].year);
    }
}