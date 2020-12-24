#include <stdio.h>

#include "../inc/sort.h"
#include "../inc/error_codes.h"

static void swap(char *d, char *s, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        char temp = *d;
        *d = *s;
        *s = temp;

        d++;
        s++;
    }
}

void mysort(void *begin, size_t elements, size_t element_size, int (*compare_fn)(const void *, const void *))
{
    if (begin == NULL || elements == 0 || element_size == 0 || compare_fn == NULL)
    {
        return;
    }

    char *pb_main = (char *) begin;

    for (size_t i = 0; i < elements - 1; i++)
    {
        char *pb_second = pb_main + element_size;

        for (size_t j = i + 1; j < elements; j++)
        {
            if ((*compare_fn)(pb_main, pb_second) > 0)
            {
                swap(pb_second, pb_main, element_size);
            }

            pb_second += element_size;
        }

        pb_main += element_size;
    }
}

int compare_int_fn(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}