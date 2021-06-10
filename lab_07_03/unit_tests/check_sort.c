#include <stdio.h>
#include <check.h>

#include "sort.h"

START_TEST(test_sort_common_pos)
{
    //void *begin, size_t elements, size_t element_size, int (*compare_fn)(const void *, const void *)
    int begin[] = {5, 3, 1, 2, 4};
    int pb_ans[] = {1, 2, 3, 4, 5}; 
    mysort(begin, 5, sizeof(int), compare_int_fn);

    int *p_ans = pb_ans;
    int *p_dst = begin;

    for (size_t i = 0; i < 4; i++)
    {
        ck_assert_int_eq(*p_ans, *p_dst);
        p_ans++;
        p_dst++;
    }
}

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_sort_common_pos);

    suite_add_tcase(s, tc_pos);

    return s;
}
