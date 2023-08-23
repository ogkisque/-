#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

const double EPS = 1e-5;

enum NumOfSolutions
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINIT_ROOTS = 1000
};

NumOfSolutions solve_equation (double a, double b, double c, double* x1, double* x2);
NumOfSolutions solve_linear (double a, double b, double* x);
NumOfSolutions solve_square (double a, double b, double c, double* x1, double* x2);
bool is_equal (double a, double b);

void input_double (double* a, double* b, double* c);
void clear_buffer ();
void output_answer (int n_roots, double x1, double x2);

int main ()
{
    printf ("# Hello! This program will solve your quadratic equation.\n");
    double a = 0, b = 0, c = 0;
    input_double (&a, &b, &c);

    double x1 = 0, x2 = 0;
    int n_roots = solve_equation (a, b, c, &x1, &x2);

    output_answer (n_roots, x1, x2);
}

NumOfSolutions solve_equation (double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
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

NumOfSolutions solve_linear (double a, double b, double* x)
{
    assert (isfinite(a));
    assert (isfinite(b));
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
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    assert (fabs(a) > EPS);
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    double des = b * b - 4 * a * c;
    if (des < -EPS)
    {
        return NO_ROOTS;
    }
    else if (is_equal (des, 0))
    {
        *x1 = -b / (2*a);
        return ONE_ROOT;
    }
    else
    {
        double sqrt_des = sqrt (des);
        *x1 = (-b - sqrt_des) / (2*a);
        *x2 = (-b + sqrt_des) / (2*a);
        return TWO_ROOTS;
    }
}

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
        clear_buffer();
        printf ("# Invalid input\n# Enter the coefficients a, b, c separated by a space\n");
    }
}

void clear_buffer ()
{
    while (getchar() != '\n')
        ;
}

bool is_equal (double a, double b)
{
    return fabs(a - b) <= EPS;
}
