#include <stdio.h>
#include "solver.h"

const int KOLVO = 5;
const char* f_name = "tests.txt";

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

void all_tests ()
{
    Test tests[KOLVO];
    read_file(f_name, tests);
    int num_of_ok_tests = 0;
    for (int i = 0; i < KOLVO; i++)
    {
        if (one_test (tests[i].a, tests[i].b, tests[i].c, tests[i].n_roots, tests[i].answer1, tests[i].answer2))
        {
            num_of_ok_tests++;
            printf("%s is OK\n", tests[i].name);
        }
        else
        {
            printf("%s is FAILED. a = %lf b = %lf c = %lf.\n", tests[i].name, tests[i].a, tests[i].b, tests[i].c);
        }
    }
}

void read_file (const char* file_name, struct Test* tests)
{
    FILE* f_tests = fopen (file_name, "r");

    for (int i = 0; i < KOLVO; i++)
        fscanf (f_tests,
                "%s %lf %lf %lf %d %lf %lf",
                tests[i].name, &tests[i].a, &tests[i].b, &tests[i].c,
                &tests[i].n_roots, &tests[i].answer1, &tests[i].answer2);

    fclose (f_tests);
}

bool one_test (double a, double b, double c, int n_roots_ref, double x1_ref, double x2_ref)
{
    double x1, x2;
    int n_roots = solve_equation (a, b, c, &x1, &x2);
    if (n_roots == n_roots_ref) {
        if (n_roots == 0) return true;
        else if (n_roots == 1) return is_equal(x1, x1_ref);
        else if (n_roots == 2) return ((is_equal(x1, x1_ref) && is_equal(x2, x2_ref)) ||
                                       (is_equal(x1, x2_ref) && is_equal(x2, x1_ref)));
        else return true;
    }
    else return false;
}
