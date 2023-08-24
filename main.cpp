#include <stdio.h>
#include <string.h>
#include "input_output.h"
#include "solver.h"
#include "solver_complex.h"
#include "output_complex.h"
#include "tests.h"

const char* FLAG_TESTS = "--tests";
const char* FLAG_COMPLEX = "--complex";

int main (int argc, char* argv[])
{
    if ((argc == 2) && (strcmp(argv[1], FLAG_TESTS) == 0))
    {
        all_tests ();
        return 0;
    }
    if ((argc == 2) && (strcmp(argv[1], FLAG_COMPLEX) == 0))
    {
        printf ("# Hello! This program will solve your quadratic equation with complex numbers.\n");
        double a = 0;
        double b = 0;
        double c = 0;
        input_double (&a, &b, &c);

        Complex x1 = {.real = 0, .imag = 0};
        Complex x2 = {.real = 0, .imag = 0};
        int n_roots = solve_equation_complex (a, b, c, &x1, &x2);

        output_answer_complex (n_roots, &x1, &x2);
        return 0;
    }

    printf ("# Hello! This program will solve your quadratic equation.\n");
    double a = 0;
    double b = 0;
    double c = 0;
    input_double (&a, &b, &c);

    double x1 = 0;
    double x2 = 0;
    int n_roots = solve_equation (a, b, c, &x1, &x2);

    output_answer (n_roots, x1, x2);
    return 0;
}
