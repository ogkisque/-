#include <stdio.h>
#include <string.h>
#include "solver.h"
#include "tests.h"


const char* FLAG_TESTS = "--tests";

int main (int argc, char* argv[])
{
    if ((argc == 3) && (strcmp(argv[1], FLAG_TESTS) == 0))
    {
        all_tests (argv[2]);
        return 0;
    }
    printf ("\033[43m# Hello! This program will solve your quadratic equation with complex numbers.\n");
    double a = 0;
    double b = 0;
    double c = 0;
    input_double (&a, &b, &c);

    Complex x1 = {.real = 0, .imag = 0};
    Complex x2 = {.real = 0, .imag = 0};
    int n_roots = solve_equation (a, b, c, &x1, &x2);

    output_answer (n_roots, &x1, &x2);
    printf("\033[0m\n");
    return 0;
}
