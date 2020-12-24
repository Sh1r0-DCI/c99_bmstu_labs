#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "funcs.h"
#include "error_codes.h"

START_TEST(test_key_bad_param)
{
    //const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst
    int rc = key(NULL, 0, 0, NULL);

    ck_assert_int_eq(rc, FILTRATION_FAILURE);
}

START_TEST(test_key_neg_el_is_first)
{
    int pb_src[] = {-1, 2, 3, 4, 5};
    int *pb_dst, *pe_dst;
    int rc = key(pb_src, pb_src + 5, &pb_dst, &pe_dst);

    ck_assert_int_eq(rc, FILTRATION_FAILURE);
}

START_TEST(test_key_common_pos)
{
    int pb_src[] = {1, 2, 3, -4, -5};
    int pb_ans[] = {1, 2, 3, -4};
    int *pb_dst, *pe_dst;   
    key(pb_src, pb_src + 5, &pb_dst, &pe_dst);

    int *p_ans = pb_ans;
    int *p_dst = pb_dst;

    for (size_t i = 0; i < 4; i++)
    {
        ck_assert_int_eq(*p_ans, *p_dst);
        p_ans++;
        p_dst++;
    }

    free(pb_dst);
}

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");
    
    tcase_add_test(tc_neg, test_key_bad_param);
    tcase_add_test(tc_neg, test_key_neg_el_is_first);

    suite_add_tcase(s, tc_neg);
    
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_common_pos);

    suite_add_tcase(s, tc_pos);

    return s;
}

