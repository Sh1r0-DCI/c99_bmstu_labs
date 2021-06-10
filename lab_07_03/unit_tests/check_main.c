#include <stdio.h>
#include <stdlib.h>

#include <check.h>

Suite* key_suite(void);
Suite* sort_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = key_suite();

    runner = srunner_create(s);

    srunner_add_suite(runner, sort_suite());

    srunner_run_all(runner, CK_VERBOSE);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}