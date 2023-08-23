#include <stdio.h>
#include <assert.h>

enum NumOfSolutions
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINIT_ROOTS = 1000
};

void input_double (double* a, double* b, double* c);
void clear_buffer ();
void output_answer (int n_roots, double x1, double x2);

void output_answer(int n_roots, double x1, double x2)
{
    switch (n_roots)
    {
    case NO_ROOTS:
        printf ("No solutions");
        break;
    case ONE_ROOT:
        printf ("1 solution: %.15lf", x1);
        break;
    case TWO_ROOTS:
        printf ("2 solutions: %.15lf %.15lf", x1, x2);
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
        clear_buffer();
        printf ("# Invalid input\n# Enter the coefficients a, b, c separated by a space\n");
    }
}

void clear_buffer ()
{
    while (getchar() != '\n')
        ;
}
