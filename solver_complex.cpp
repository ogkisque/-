#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "solver_complex.h"

const double EPS = 1e-8;

NumOfSolutions solve_linear_complex (double a, double b, Complex* x)
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

NumOfSolutions solve_square_complex (double a, double b, double c, Complex* x1, Complex* x2)
{
    // check struct fields
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

NumOfSolutions solve_equation_complex (double a, double b, double c, Complex* x1, Complex* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (is_equal(a, 0))
    {
        return solve_linear_complex (b, c, x1);
    }
    else
    {
        return solve_square_complex (a, b, c, x1, x2);
    }
}

