#include <stdio.h>
#include <assert.h>
#include "input_output.h"

void output_answer(int n_roots, double x1, double x2)
{
    switch (n_roots)
    {
    case NO_ROOTS:
        printf ("No solutions");
        break;
    case ONE_ROOT:
        printf ("1 solution: %.5lf", x1);
        break;
    case TWO_ROOTS:
        printf ("2 solutions: %.5lf %.5lf", x1, x2);
        break;
    case INFINIT_ROOTS:
        printf ("Infinite number of solutions");
        break;
    default:
        assert (!"Problem is in the output_answer function");
        break;
    }
}

void input_double (double* a, double* b, double* c)
{
    printf ("# Enter the coefficients a, b, c separated by a space\n");
    while (scanf ("%lf %lf %lf", a, b, c) != 3)
    {
        clear_buffer ();
        printf ("# Invalid input\n"
                "# Enter the coefficients a, b, c separated by a space\n");
    }
}

void clear_buffer ()
{
    while (getchar() != '\n')
        ;
}
