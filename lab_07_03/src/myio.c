#include "../inc/myio.h"
#include "../inc/error_codes.h"


int read_from_file(FILE *f_in, int *in_array_begin, int n, int **in_array_end)
{
    for (*in_array_end = in_array_begin; n > 0; (*in_array_end)++, n--)
    {
        if (fscanf(f_in, "%d", *in_array_end) != 1)
        {
            return INPUT_ERROR;
        }
    }

    return OK;
}

void print_to_file(FILE *f_out, int *out_array_begin, int *out_array_end)
{
    for (int *i_p = out_array_begin; i_p != out_array_end; ++i_p)
    {
        fprintf(f_out, "%d ", (*i_p));
    }
}