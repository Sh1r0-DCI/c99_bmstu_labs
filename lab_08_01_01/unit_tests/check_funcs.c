#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../inc/funcs.h"
#include "../inc/error_codes.h"
#include "../inc/strucs.h"

int cmp_matrixes(matrix_t *a, matrix_t *b)
{
    if (a->rows != b->rows || a->cols != b->cols)
    {
        return 0;
    }

    for (size_t i = 0; i < a->rows; i++)
    {
       for (size_t j = 0; j < a->cols; j++)
       {
           if (a->data[i][j] != b->data[i][j])
           {
               return 0;
           }
       }
    }

    return 1;
}

START_TEST(test_matrix_transform_1_cols)
{
    matrix_t *a = 0, *ans = 0;
    a->rows = 2;
    a->cols = 3;
    a->data[0][0] = 4;
    a->data[0][1] = 7;
    a->data[0][2] = 1;
    a->data[1][0] = 3;
    a->data[1][1] = 2;
    a->data[1][2] = 7;
    //     {4, 7, 1},
    //     {3, 2, 7}
    // };

    ans->rows = 2;
    ans->cols = 2;
    ans->data[0][0] = 4;
    ans->data[0][1] = 1;
    ans->data[1][0] = 3;
    ans->data[1][1] = 7;
    //     {4, 1},
    //     {3, 7}
    // };

    matrix_transform_1(&a);

    int c = cmp_matrixes(a, ans);
    ck_assert_int_eq(c, 1);
}

START_TEST(test_matrix_transform_1_rows)
{
    matrix_t *a = 0, *ans = 0;
    a->rows = 5;
    a->cols = 3;
    a->data[0][0] = 0;
    a->data[0][1] = 2;
    a->data[0][2] = 9;
    a->data[1][0] = 1;
    a->data[1][1] = 2;
    a->data[1][2] = 2;
    a->data[2][0] = 3;
    a->data[2][1] = 3;
    a->data[2][2] = 3;
    a->data[3][0] = 8;
    a->data[3][1] = 8;
    a->data[3][2] = 2;
    a->data[4][0] = 1;
    a->data[4][1] = 8;
    a->data[4][2] = 3;
    //     {0, 2, 9},
    //     {1, 2, 2},
    //     {3, 3, 3},
    //     {8, 8, 2},
    //     {1, 8, 3}
    // };

    ans->rows = 3;
    ans->cols = 3;
    ans->data[0][0] = 0;
    ans->data[0][1] = 2;
    ans->data[0][2] = 9;
    ans->data[1][0] = 1;
    ans->data[1][1] = 2;
    ans->data[1][2] = 2;
    ans->data[2][0] = 3;
    ans->data[2][1] = 3;
    ans->data[2][2] = 3;
    //     {1, 2, 2},
    //     {3, 3, 3},
    //     {1, 8, 3}
    // };

    matrix_transform_1(&a);

    int c = cmp_matrixes(a, ans);
    ck_assert_int_eq(c, 1);
}

START_TEST(test_matrix_transform_2)
{
    matrix_t *a = 0, *ans = 0;
    a->rows = 2;
    a->cols = 2;
    a->data[0][0] = 4;
    a->data[0][1] = 1;
    a->data[1][0] = 3;
    a->data[1][1] = 7;
    //     {4, 1},
    //     {3, 7}
    // };

    ans->rows = 3;
    ans->cols = 3;
    ans->data[0][0] = 4;
    ans->data[0][1] = 1;
    ans->data[0][2] = 4;
    ans->data[1][0] = 3;
    ans->data[1][1] = 7;
    ans->data[1][2] = 7;
    ans->data[2][0] = 3;
    ans->data[2][1] = 4;
    ans->data[2][2] = 4;
    //     {4, 1, 4},
    //     {3, 7, 7},
    //     {3, 4, 4}
    // };

    matrix_transform_2(a, 3);

    int c = cmp_matrixes(a, ans);
    ck_assert_int_eq(c, 1);
}

START_TEST(test_matrix_transform_3_neg)
{
    matrix_t *a = 0, *b = 0, *ans = 0;
    a->rows = 3;
    a->cols = 3;
    a->data[0][0] = 4;
    a->data[0][1] = 1;
    a->data[0][2] = 4;
    a->data[1][0] = 3;
    a->data[1][1] = 7;
    a->data[1][2] = 7;
    a->data[2][0] = 3;
    a->data[2][1] = 4;
    a->data[2][2] = 4;
    //     {4, 1, 4},
    //     {3, 7, 7},
    //     {3, 4, 4}
    // };

    b->rows = 3;
    b->cols = 3;
    b->data[0][0] = 1;
    b->data[0][1] = 2;
    b->data[0][2] = 2;
    b->data[1][0] = 3;
    b->data[1][1] = 3;
    b->data[1][2] = 3;
    b->data[2][0] = 1;
    b->data[2][1] = 8;
    b->data[2][2] = 3;
    //     {1, 2, 2},
    //     {3, 3, 3},
    //     {1, 8, 3}
    // };

    ans->rows = 3;
    ans->cols = 3;
    ans->data[0][0] = 15464;
    ans->data[0][1] = 34369;
    ans->data[0][2] = 22134;
    ans->data[1][0] = 36567;
    ans->data[1][1] = 81282;
    ans->data[1][2] = 52327;
    ans->data[2][0] = 22680;
    ans->data[2][1] = 50421;
    ans->data[2][2] = 32461;
    //     {15464, 34369, 22134},
    //     {36567, 81282, 52327},
    //     {22680, 50421, 32461}
    // };

    matrix_t *result = matrix_transform_3(a, b, -2, 3);

    int c = cmp_matrixes(result, ans);
    ck_assert_int_eq(c, 1);
}

START_TEST(test_matrix_transform_3_pos)
{
    matrix_t *a = 0, *b = 0, *ans = 0;
    a->rows = 3;
    a->cols = 3;
    a->data[0][0] = 4;
    a->data[0][1] = 1;
    a->data[0][2] = 4;
    a->data[1][0] = 3;
    a->data[1][1] = 7;
    a->data[1][2] = 7;
    a->data[2][0] = 3;
    a->data[2][1] = 4;
    a->data[2][2] = 4;
    //     {4, 1, 4},
    //     {3, 7, 7},
    //     {3, 4, 4}
    // };

    b->rows = 3;
    b->cols = 3;
    b->data[0][0] = 1;
    b->data[0][1] = 2;
    b->data[0][2] = 2;
    b->data[1][0] = 3;
    b->data[1][1] = 3;
    b->data[1][2] = 3;
    b->data[2][0] = 1;
    b->data[2][1] = 8;
    b->data[2][2] = 3;
    //     {1, 2, 2},
    //     {3, 3, 3},
    //     {1, 8, 3}
    // };

    ans->rows = 3;
    ans->cols = 3;
    ans->data[0][0] = 15464;
    ans->data[0][1] = 34369;
    ans->data[0][2] = 22134;
    ans->data[1][0] = 36567;
    ans->data[1][1] = 81282;
    ans->data[1][2] = 52327;
    ans->data[2][0] = 22680;
    ans->data[2][1] = 50421;
    ans->data[2][2] = 32461;
    //     {15464, 34369, 22134},
    //     {36567, 81282, 52327},
    //     {22680, 50421, 32461}
    // };

    matrix_t *result = matrix_transform_3(a, b, 2, 3);

    int c = cmp_matrixes(result, ans);
    ck_assert_int_eq(c, 1);
}

Suite* funcs_suite(void)
{
    Suite *s;
    TCase *tc_transform_1;
    TCase *tc_transform_2;
    TCase *tc_transform_3;

    s = suite_create("transform");

    tc_transform_1 = tcase_create("transform_1");
    
    tcase_add_test(tc_transform_1, test_matrix_transform_1_cols);
    tcase_add_test(tc_transform_1, test_matrix_transform_1_rows);

    suite_add_tcase(s, tc_transform_2);
    
    tc_transform_2 = tcase_create("transform_2");
    
    tcase_add_test(tc_transform_2, test_matrix_transform_2);

    suite_add_tcase(s, tc_transform_2);

    tc_transform_3 = tcase_create("transform_3");
    
    tcase_add_test(tc_transform_3, test_matrix_transform_3_neg);
    tcase_add_test(tc_transform_3, test_matrix_transform_3_pos);

    suite_add_tcase(s, tc_transform_3);

    return s;
}

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = funcs_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}