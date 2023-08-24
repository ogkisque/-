#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "solver.h"

/*
enum NumOfSolutions
{
    INFINIT_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};
*/

bool is_equal (double a, double b)
{
    assert (isfinite (a));
    assert (isfinite (b));

    return (fabs(a - b) <= EPS);
}

NumOfSolutions solve_linear (double a, double b, double* x)
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
        *x = -b / a;
        return ONE_ROOT;
    }
}

NumOfSolutions solve_square (double a, double b, double c, double* x1, double* x2)
{
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
        return NO_ROOTS;
    }
    else if (is_equal (discr, 0))
    {
        *x1 = -b / (2*a);
        return ONE_ROOT;
    }
    else
    {
        double sqrt_des = sqrt (discr);
        *x1 = (-b - sqrt_des) / (2*a);
        *x2 = (-b + sqrt_des) / (2*a);
        return TWO_ROOTS;
    }
}

NumOfSolutions solve_equation (double a, double b, double c, double* x1, double* x2)
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
