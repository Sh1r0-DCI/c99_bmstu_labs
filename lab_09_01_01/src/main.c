#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "myio.h"
#include "parse_args.h"
#include "operating_funcs.h"

int main(int argc, char **argv) // app.exe FILE{title/name/year} FIELD [KEY]
{
    FILE *f = NULL;
    char filename[FILENAME_SIZE];
    char *field = NULL;
    char *key = NULL;

    int rc = OK;

    film_info *films = NULL;
    int num_of_films = -1;

    if((rc = parse_args((const int) argc, (const char**) argv, filename, &field, &key)) != OK)
        return rc;

    // printf("filename is: %s?\n", filename);
    printf("field=%s, key=%s\n", field, key);
    f = fopen(filename, "r");

    if (!f)
        return FILE_ERROR;

    if ((rc = alloc_struc_array(f, &films, &num_of_films)) != OK)
    {
        free_array(films, num_of_films);
        return rc;
    }
    printf("alloc finished ok.....(probably ok)\n");

    if ((rc = input_strucs_from_file(f, films, num_of_films, field)) != OK)
    {
        free_array(films, num_of_films);
        printf("rc = %d", rc);
        return rc;
    }
    // printf("input finished ok.....(probably ok)\n");
    
    // if (key == NULL)
    // {
    // // sort strucs by field
    // // output

    // }
    // else
    // {
    // // Bin search on field and key and output info
    // // "Not found" if not

    // }

    printf("printing array...\n");
    print_strucs_array(films, num_of_films);

    free_array(films, num_of_films);
    free(field);
    free(key);

    return fclose(f);
}