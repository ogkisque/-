#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "tests.h"
#include "solver.h"

const int NUM_TESTS = 10;
const char* f_name = "tests.txt";

bool is_equal_test (double a, double b)
{
    assert (isfinite (a));
    assert (isfinite (b));

    const double EPS_TESTS = 1e-5;

    return (fabs(a - b) <= EPS_TESTS);
}

void swap(double* x1, double* x2)
{
    double tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}

void read_file (const char* file_name, struct Test* tests)
{
    FILE* f_tests = fopen (file_name, "r");

    assert (f_tests != NULL);

    for (int i = 0; i < NUM_TESTS; i++)
        fscanf (f_tests,
                "%s %lf %lf %lf %d %lf %lf",
                tests[i].name, &tests[i].a, &tests[i].b, &tests[i].c,
                &tests[i].n_roots, &tests[i].answer1, &tests[i].answer2);

    fclose (f_tests);
}

void all_tests ()
{
    Test tests[NUM_TESTS] = {};
    read_file("tests.txt", tests);

    assert (tests != NULL);

    int num_of_ok_tests = 0;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        double x1 = 0;
        double x2 = 0;
        int n_roots = solve_equation(tests[i].a, tests[i].b, tests[i].c, &x1, &x2);

        // sort roots
        if (x1 > x2)
        {
            swap(&x1, &x2);
        }

        if ((n_roots == tests[i].n_roots) &&
            (is_equal_test(x1, tests[i].answer1)) &&
            (is_equal_test(x2, tests[i].answer2)))
        {
            num_of_ok_tests++;
            printf("%*s is OK\n", SIZE_OF_NAME, tests[i].name);
        }
        else
        {
            printf("%*s is FAILED. a = %lf b = %lf c = %lf\n"
                   "Expected: %d num of roots, x1 = %lf, x2 = %lf,"
                   "but got %d num of roots, x1 = %lf, x2 = %lf\n",
                    SIZE_OF_NAME, tests[i].name, tests[i].a, tests[i].b, tests[i].c,
                    tests[i].n_roots, tests[i].answer1, tests[i].answer2,
                    n_roots, x1, x2);
        }
    }

    printf("%d tests from %d is OK\n\n", num_of_ok_tests, NUM_TESTS);
}
