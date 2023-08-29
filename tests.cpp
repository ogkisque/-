#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

#include "tests.h"
#include "colors.h"

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

Test* read_file (const char* file_name, int* num_tests, Errors* error)
{
    assert (file_name != NULL);

    FILE* f_tests = fopen (file_name, "r");

    if (f_tests == NULL)
    {
        *error = ERROR_FILE_OPEN;
        return NULL;
    }

    const int MAX_LENGTH_TESTS = 100;
    char c[MAX_LENGTH_TESTS];
    while (fgets(c, MAX_LENGTH_TESTS, f_tests) != NULL)
    {
        (*num_tests)++;
    }
    rewind (f_tests);

    Test* tests = (Test*) calloc (*num_tests, sizeof (Test));

    if (tests == NULL)
    {
        *error = ERROR_OF_MEMORY;
        return NULL;
    }

    for (int i = 0; i < *num_tests; i++)
    {
        fscanf (f_tests,
                "%s %lf %lf %lf %d %lf %lf %lf %lf",
                tests[i].name, &tests[i].coeffs.a, &tests[i].coeffs.b, &tests[i].coeffs.c,
                &tests[i].n_roots, &tests[i].roots.x1.real, &tests[i].roots.x1.imag,
                &tests[i].roots.x2.real, &tests[i].roots.x2.imag);
    }

    fclose (f_tests);
    return tests;
}

Errors all_tests (const char* file_name)
{
    int num_tests = 0;
    Errors error = CORRECT;
    Test* tests = read_file (file_name, &num_tests, &error);
    switch (error)
    {
    case ERROR_FILE_OPEN:
        return ERROR_FILE_OPEN;
        break;
    case ERROR_OF_MEMORY:
        return ERROR_OF_MEMORY;
        break;
    case CORRECT:
        break;
    default:
        break;
    }

    int num_ok_tests = 0;
    int i = 0;
    while (i < num_tests)
    {
        Complex x1 = {.real = 0, .imag = 0};
        Complex x2 = {.real = 0, .imag = 0};
        int n_roots = solve_equation(&(tests[i].coeffs), &x1, &x2);

        if (x1.real > x2.real)
            swap(&x1, &x2);
        if (x1.imag > x2.imag)
            swap(&x1, &x2);

        if (test_is_ok (n_roots, tests[i].n_roots, &x1, &x2, &(tests[i].roots)))
        {
            num_ok_tests++;
            print_ok (tests[i].name);
        }
        else
        {

            print_failed (&(tests[i]), n_roots, &x1, &x2);
        }
        i++;
    }
    print_end_tests (num_ok_tests, num_tests);
    free (tests);
    return CORRECT;
}


bool test_is_ok (int n_roots, int n_roots_ref, const Complex* x1, const Complex* x2, const Roots* roots)
{
    return ((n_roots == n_roots_ref) &&
            (is_equal_test(x1->real, (roots->x1).real)) &&
            (is_equal_test(x1->imag, (roots->x1).imag)) &&
            (is_equal_test(x2->real, (roots->x2).real)) &&
            (is_equal_test(x2->imag, (roots->x2).imag)));
}

void print_end_tests (int num_ok_tests, int num_tests)
{
    printf("%d tests from %d is OK\n", num_ok_tests, num_tests);
}

void print_ok (const char* name)
{
    assert (name != NULL);

    printf(GREEN_COLOR "%*s is OK" OFF_COLOR "\n", SIZE_OF_NAME, name);
}

void print_failed (const Test* test, int n_roots, const Complex* x1, const Complex* x2)
{
    assert (isfinite ((test->coeffs).a));
    assert (isfinite ((test->coeffs).b));
    assert (isfinite ((test->coeffs).c));
    assert (isfinite (test->n_roots));
    assert (isfinite (n_roots));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (test != NULL);

    char str_x1_ref[MAX_LENGTH];
    char str_x2_ref[MAX_LENGTH];
    char str_x1[MAX_LENGTH];
    char str_x2[MAX_LENGTH];
    print_complex (&((test->roots).x1), str_x1_ref);
    print_complex (&((test->roots).x2), str_x2_ref);
    print_complex (x1, str_x1);
    print_complex (x2, str_x2);
    printf (RED_COLOR "%*s is FAILED.\n"
            "a = %.3lf, b = %.3lf, c = %.3lf\n"
            "Expected: %d num of roots, x1 = %s, x2 = %s\n"
            "Got       %d num of roots, x1 = %s, x2 = %s" OFF_COLOR "\n",
            SIZE_OF_NAME, test->name, (test->coeffs).a, (test->coeffs).a, (test->coeffs).a,
            test->n_roots, str_x1_ref, str_x2_ref,
            n_roots, str_x1, str_x2);
}
