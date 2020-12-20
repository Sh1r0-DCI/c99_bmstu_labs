#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "../inc/funcs.h"
#include "../inc/myio.h"
#include "../inc/sort.h"
#include "../inc/error_codes.h"

int main(int argc, char *argv[]) {
    FILE *f_in;
    FILE *f_out;
    int numbers;
    int *in_array_begin = 0, *in_array_end = 0;
    int *out_array_begin = 0, *out_array_end = 0;

    if (argc < 3 || argc > 4)
    {
        return ARGS_INPUT_ERROR;
    }
	
	
    f_in = fopen(argv[1], "r");

    if (f_in == NULL)
    {
        return UNEXISTING_FILE;
    }

    f_out = fopen(argv[2], "w");

    if (f_out == NULL)
    {
        fclose(f_in);
        return FOPEN_ERROR;
    }

    if (fget_numbers(f_in, &numbers) == INPUT_ERROR)
    {
        fclose(f_in);
        fclose(f_out);
        return INPUT_ERROR;
    }

    if (numbers > 0)
    {
        int filtered;

        in_array_begin = calloc(numbers, sizeof(int));

        rewind(f_in);

        if(read_from_file(f_in, in_array_begin, numbers, &in_array_end))
        {
            return INPUT_ERROR;
        }

        printf("read ok\n");

        if (argc == 4 && (*argv[3]) == 'f')
        {
            if(key(in_array_begin, in_array_end, &out_array_begin, &out_array_end))
            {
                return FILTRATION_FAILURE;
            }
        }

        else if (argc == 4 && (*argv[3]) != 'f')
        {
            return ARGS_INPUT_ERROR;
        }
        printf("key ok\n");

        filtered = out_array_end - out_array_begin;

        mysort(out_array_begin, filtered, sizeof(int), compare_int_fn);
        printf("sort ok\n");

        print_to_file(f_out, out_array_begin, out_array_end);

        free(in_array_begin);
        free(out_array_begin);

    }
    
    else
    {
        return EMPTY_FILE;
    }

    fclose(f_in);
    fclose(f_out);
    return OK;
}