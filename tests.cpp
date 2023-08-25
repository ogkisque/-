#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "tests.h"

bool is_equal_test (double a, double b)
{
    assert (isfinite (a));
    assert (isfinite (b));

    const double EPS_TESTS = 1e-5;

    return (fabs(a - b) <= EPS_TESTS);
}

void swap(Complex* a, Complex* b)
{
    Complex tmp = *a;
    *a = *b;
    *b = tmp;
}

Test* read_file (const char* file_name, int* num_tests)
{
    FILE* f_tests = fopen (file_name, "r");
    assert (f_tests != NULL);

    char c[100];
    while (fgets(c, 100, f_tests) != NULL)
    {
        (*num_tests)++;
    }
    rewind(f_tests);

    Test* tests = (Test*) calloc (*num_tests, sizeof (Test));
    assert (tests != NULL);

    for (int i = 0; i < *num_tests; i++)
    {
        fscanf (f_tests,
                "%s %lf %lf %lf %d %lf %lf %lf %lf",
                tests[i].name, &tests[i].a, &tests[i].b, &tests[i].c,
                &tests[i].n_roots, &tests[i].x1_real_ref, &tests[i].x1_imag_ref,
                &tests[i].x2_real_ref, &tests[i].x2_imag_ref);
    }

    fclose (f_tests);
    return tests;
}

void all_tests (const char* file_name)
{
    int num_tests = 0;
    Test* tests = read_file(file_name, &num_tests);

    assert (tests != NULL);

    int num_ok_tests = 0;
    int i = 0;
    while (i < num_tests)
    {
        Complex x1 = {.real = 0, .imag = 0};
        Complex x2 = {.real = 0, .imag = 0};
        int n_roots = solve_equation(tests[i].a, tests[i].b, tests[i].c, &x1, &x2);

        if (x1.real > x2.real)
            swap(&x1, &x2);
        if (x1.imag > x2.imag)
            swap(&x1, &x2);

        if ((n_roots == tests[i].n_roots) &&
            (is_equal_test(x1.real, tests[i].x1_real_ref)) &&
            (is_equal_test(x1.imag, tests[i].x1_imag_ref)) &&
            (is_equal_test(x2.real, tests[i].x2_real_ref)) &&
            (is_equal_test(x2.imag, tests[i].x2_imag_ref)))
        {
            num_ok_tests++;
            printf("\033[32m%*s is OK\033[0m\n", SIZE_OF_NAME, tests[i].name);
        }
        else
        {
            Complex x1_ref = {.real = tests[i].x1_real_ref,
                              .imag = tests[i].x1_imag_ref};
            Complex x2_ref = {.real = tests[i].x2_real_ref,
                              .imag = tests[i].x2_imag_ref};
            printf("\033[31m%*s is FAILED.\n"
                   "a = %lf, b = %lf, c = %lf\n"
                   "Expected: %d num of roots, x1 = ",
                   SIZE_OF_NAME, tests[i].name, tests[i].a, tests[i].b, tests[i].c,
                   tests[i].n_roots);
            print_complex(&x1_ref);
            printf(", x2 = ");
            print_complex(&x2_ref);
            printf("\n");
            printf("Got:      %d num of roots, x1 = ", n_roots);
            print_complex(&x1);
            printf(", x2 = ");
            print_complex(&x2);
            printf("\033[0m\n");
        }
        i++;
    }
    printf("%d tests from %d is OK\n", num_ok_tests, num_tests);
    free(tests);
}
