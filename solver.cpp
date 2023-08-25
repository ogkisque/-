#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "solver.h"

const double EPS = 1e-8;

NumOfSolutions solve_linear (double a, double b, Complex* x)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (x != NULL);

    if (is_equal (a, 0))
    {
        return is_equal(b, 0) ? INFINIT_ROOTS : NO_ROOTS;

    }
    else
    {
        x->real = -b / a;
        x->imag = 0;
        return ONE_ROOT;
    }
}

NumOfSolutions solve_square (double a, double b, double c, Complex* x1, Complex* x2)
{
    assert (isfinite (x1->real));
    assert (isfinite (x2->real));
    assert (isfinite (x1->imag));
    assert (isfinite (x2->imag));
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (!is_equal (a, 0));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    double discr = b * b - 4 * a * c;

    if (discr < -EPS)
    {
        double sqrt_discr = sqrt (fabs(discr));
        x1->real = -b / 2 / a;
        x1->imag = sqrt_discr / 2 / a;
        x2->real = x1->real;
        x2->imag = -sqrt_discr / 2 / a;
        return TWO_ROOTS;
    }
    else if (is_equal (discr, 0))
    {
        x1->real = -b / 2 / a;
        return ONE_ROOT;
    }
    else
    {
        double sqrt_discr = sqrt (discr);
        x1->real = (-b - sqrt_discr) / 2 / a;
        x2->real = (-b + sqrt_discr) / 2 / a;
        return TWO_ROOTS;
    }
}

NumOfSolutions solve_equation (double a, double b, double c, Complex* x1, Complex* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (is_equal(a, 0))
    {
        return solve_linear (b, c, x1);
    }
    else
    {
        return solve_square (a, b, c, x1, x2);
    }
}

bool is_equal (double a, double b)
{
    assert (isfinite (a));
    assert (isfinite (b));

    return (fabs(a - b) <= EPS);
}

double make_negative_zero (double x)
{
    return (is_equal (x, 0)) ? 0 : x;
}

void output_answer (int n_roots, Complex* x1, Complex* x2)
{
    x1->real = make_negative_zero(x1->real);
    x2->real = make_negative_zero(x2->real);
    x1->imag = make_negative_zero(x1->imag);
    x2->imag = make_negative_zero(x2->imag);

    switch (n_roots)
    {
    case NO_ROOTS:
        printf ("No solutions");
        break;
    case ONE_ROOT:
        printf ("1 solution: x = ");
        print_complex (x1);
        break;
    case TWO_ROOTS:
        printf ("2 solutions: x1 = ");
        print_complex (x1);
        printf (", x2 = ");
        print_complex (x2);
        break;
    case INFINIT_ROOTS:
        printf ("Infinite number of solutions");
        break;
    default:
        assert (!"Problem is in the output_answer function");
        break;
    }
}

void print_complex (Complex* x)
{
    printf ("%.5lf", x->real);
    if (x->imag >= 0)
        printf(" + %.5lfi", x->imag);
    else
        printf(" - %.5lfi", fabs(x->imag));
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
