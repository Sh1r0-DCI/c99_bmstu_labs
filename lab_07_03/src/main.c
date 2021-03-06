#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "../inc/funcs.h"
#include "../inc/myio.h"
#include "../inc/sort.h"
#include "../inc/error_codes.h"

int main(int argc, char *argv[])
{
    FILE *f_in;
    FILE *f_out;
    int numbers;
    int *in_array_begin, *in_array_end;
    int *out_array_begin, *out_array_end;

    if (argc < 3 || argc > 4)
    {
        return ARGS_INPUT_ERROR;
    }
	
	
    f_in = fopen(argv[1], "r");

    if (f_in == NULL)
    {
        return UNEXISTING_FILE;
    }

    if (fget_numbers(f_in, &numbers) == INPUT_ERROR)
    {
        if (fclose(f_in))
            return FCLOSE_ERROR;
        return INPUT_ERROR;
    }

    if (numbers > 0)
    {
        int filtered;

        in_array_begin = calloc(numbers, sizeof(int));

        rewind(f_in);

        if (read_from_file(f_in, in_array_begin, numbers, &in_array_end))
        {
            free(in_array_begin);
            return INPUT_ERROR;
        }

        f_out = fopen(argv[2], "w");

        if (f_out == NULL)
        {
            free(in_array_begin);
            if (fclose(f_in))
                return FCLOSE_ERROR;
            return FOPEN_ERROR;
        }

        if (argc == 4 && (*argv[3]) != 'f')
        {
            free(in_array_begin);
            return ARGS_INPUT_ERROR;
        }
        else if (argc == 4 && (*argv[3]) == 'f')
        {
            if (key(in_array_begin, in_array_end, &out_array_begin, &out_array_end))
            {
                free(in_array_begin);
                return FILTRATION_FAILURE;
            }

            filtered = out_array_end - out_array_begin;
            //printf("started sorting\n");
            mysort(out_array_begin, filtered, sizeof(int), compare_int_fn);
            //printf("sort ok\n");
            print_to_file(f_out, out_array_begin, out_array_end);
            free(in_array_begin);
            free(out_array_begin);
        }
        else
        {
            //printf("started sorting\n");
            mysort(in_array_begin, numbers, sizeof(int), compare_int_fn);
            //printf("sort ok, starting printing in_array\n");
            print_to_file(f_out, in_array_begin, in_array_end);
            free(in_array_begin);
        }
    }
    else
    {
        return EMPTY_FILE;
    }

    if (fclose(f_in) || fclose(f_out))
        return FCLOSE_ERROR;
    return OK;
}