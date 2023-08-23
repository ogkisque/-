#include <stdio.h>
#include <math.h>
#include "solver.h"

const int NUM_TESTS = 10;
const char* f_name = "tests.txt";
const double EPS_TESTS = 1e-5;

struct Test
{
    char name[100];
    double a;
    double b;
    double c;
    int n_roots;
    double answer1;
    double answer2;
};

void read_file (const char* file_name, struct Test* tests);
void all_tests ();
bool one_test (double a, double b, double c, int n_roots_ref, double x1_ref, double x2_ref);
bool is_equal_test (double a, double b);

void all_tests ()
{
    Test tests[NUM_TESTS];
    read_file(f_name, tests);
    int num_of_ok_tests = 0;
    for (int i = 0; i < NUM_TESTS; i++)
    {
        double x1 = 0, x2 = 0;
        int n_roots = solve_equation(tests[i].a, tests[i].b, tests[i].c, &x1, &x2);
        if (n_roots == tests[i].n_roots)
        {
            if (n_roots == 0 || n_roots == -1)
            {
                num_of_ok_tests++;
                printf("%25s is OK\n", tests[i].name);
            }
            else if (n_roots == 1)
            {
                if (is_equal_test (x1, tests[i].answer1))
                {
                    num_of_ok_tests++;
                    printf("%25s is OK\n", tests[i].name);
                }
                else
                    printf("%25s is FAILED. a = %lf b = %lf c = %lf\n"
                    "Expected: %d num of roots, x1 = %lf, x2 = %lf, but got %d num of roots, x1 = %lf, x2 = %lf\n",
                    tests[i].name, tests[i].a, tests[i].b, tests[i].c, tests[i].n_roots, tests[i].answer1, tests[i].answer2,
                    n_roots, x1, x2);
            }
            else
            {
                if ((is_equal_test (x1, tests[i].answer1) && is_equal_test (x2, tests[i].answer2)) ||
                    (is_equal_test (x2, tests[i].answer1) && is_equal_test (x1, tests[i].answer2)))
                {
                    num_of_ok_tests++;
                    printf("%25s is OK\n", tests[i].name);
                }
                else
                    printf("%25s is FAILED. a = %lf b = %lf c = %lf\n"
                    "Expected: %d num of roots, x1 = %lf, x2 = %lf, but got %d num of roots, x1 = %lf, x2 = %lf\n",
                    tests[i].name, tests[i].a, tests[i].b, tests[i].c, tests[i].n_roots, tests[i].answer1, tests[i].answer2,
                    n_roots, x1, x2);
            }
        }
        else
            printf("%25s is FAILED. a = %lf b = %lf c = %lf\n"
                "Expected: %d num of roots, x1 = %lf, x2 = %lf, but got %d num of roots, x1 = %lf, x2 = %lf\n",
                tests[i].name, tests[i].a, tests[i].b, tests[i].c, tests[i].n_roots, tests[i].answer1, tests[i].answer2,
                n_roots, x1, x2);
    }
    printf("%d tests from %d is OK\n\n", num_of_ok_tests, NUM_TESTS);
}

void read_file (const char* file_name, struct Test* tests)
{
    FILE* f_tests = fopen (file_name, "r");

    for (int i = 0; i < NUM_TESTS; i++)
        fscanf (f_tests,
                "%s %lf %lf %lf %d %lf %lf",
                tests[i].name, &tests[i].a, &tests[i].b, &tests[i].c,
                &tests[i].n_roots, &tests[i].answer1, &tests[i].answer2);

    fclose (f_tests);
}

bool is_equal_test (double a, double b)
{
    return (fabs(a - b) <= EPS_TESTS);
}
