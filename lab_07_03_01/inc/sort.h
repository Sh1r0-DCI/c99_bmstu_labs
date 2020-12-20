#ifndef _SORT_H_

#define _SORT_H_


void mysort(void *begin, size_t elements, size_t element_size, int (*compare_fn)(const void *, const void *));
int compare_int_fn(const void *a, const void *b);


#endif