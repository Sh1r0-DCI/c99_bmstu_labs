#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myio.h"
#include "operating_funcs.h"


int input_strucs_from_file(FILE *f, film_info *films, int num_of_films, char *field) // strucs are instantly sorted
{
    char *tempstuff = strdup(field);
    tempstuff++;

    for (int i = 0; i < (num_of_films) && !feof(f); i++)
    {
        char  *line_title = NULL;
        char  *line_name = NULL;
        char  *line_year = NULL;
        int    temp_year;
        size_t len = 0;

        if (getline(&line_title, &len, f) == -1)
        {
            printf("problems officer?\n");
            return INPUT_ERROR;
        }

        if (getline(&line_name, &len, f) == -1)
        {
            printf("problems officer?\n");
            return INPUT_ERROR;
        }

        if (getline(&line_year, &len, f) == -1)
        {
            printf("problems officer?\n");
            return INPUT_ERROR;
        }

        temp_year = (int) strtol(line_year, (char **)NULL, 10);

        if (temp_year < CINEMA_INVENTION_DATE)
        {
            printf("input interrupt {year}\n");
            return INCORECT_DATE;
        }

        if (insert_struc(films, i, field, line_title, line_name, temp_year))
        {
            return ALLOC_ERROR;
        }

        free(line_title);
        free(line_name);
        free(line_year);
    }
        
    return OK;
}

void print_strucs_array(film_info *films, int num_of_films) 
{
    int answer = -1;

    printf("num of films is %d\n", num_of_films);

    if (num_of_films > 20)
    {
        printf("Too much films. Still print them all?\n");
        printf("Answer(0 - No, 1 - Yes): ");

        int rc = scanf("%d", &answer);
        getc(stdin);

        if(rc != 1)
        {
            printf("\nWrong input...Starting over.\n\n");
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
        printf("\n________________________________\n");
        printf("%s%s%d\n", films[i].title, films[i].director_name, films[i].year);
        printf("________________________________\n");
    }
}