#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

const double EPS = 1e-5;

double input (const char* coeff_name);
bool is_equal (double a, double b);
void output_answer (int n_roots, double x1, double x2);
int solve_equation (double a, double b, double c, double* x1, double* x2);
int solve_linear (double a, double b, double* x);
int solve_square (double a, double b, double c, double* x1, double* x2);
bool end_input (char last_c);

enum n_solutions
{
    ZERO, ONE, TWO, INFINIT = 1000
};

int main ()
{
    printf ("# Hello! This program will solve your quadratic equation.\n");
    double a = input ("a"),
           b = input ("b"),
           c = input ("c");

    double x1 = 0, x2 = 0;
    int n_roots = solve_equation (a, b, c, &x1, &x2);

    output_answer (n_roots, x1, x2);
}

int solve_equation (double a, double b, double c, double* x1, double* x2)
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

int solve_linear (double a, double b, double* x)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert (x != NULL);

    if (is_equal(a, 0))
    {
        if (is_equal(b, 0))
            return INFINIT;
        else
            return ZERO;
    }
    else
    {
        *x = -b / a;
        return ONE;
    }
}

int solve_square (double a, double b, double c, double* x1, double* x2)
{
    assert (a != 0);
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    double des = b*b - 4*a*c;
    if (des < -EPS)
    {
        return ZERO;
    }
    else if (is_equal(des, 0))
    {
        *x1 = -b / (2*a);
        return ONE;
    }
    else
    {
        double sqrt_des = sqrt(des);
        *x1 = (-b - sqrt_des) / (2*a);
        *x2 = (-b + sqrt_des) / (2*a);
        return TWO;
    }
}

void output_answer(int n_roots, double x1, double x2)
{
    switch (n_roots) {
    case ZERO:
        printf ("No solutions");
        break;
    case ONE:
        printf ("1 solution: %.5lf", x1);
        break;
    case TWO:
        printf ("2 solutions: %.5lf %.5lf", x1, x2);
        break;
    case INFINIT:
        printf ("Infinite number of solutions");
        break;
    default:
        assert (0);
        break;
    }
}

double input (const char* coeff_name)
{
    double coeff = 0;
    printf ("# Enter the coefficient ");
    printf("%s", coeff_name);
    printf("\n");
    while (!(scanf("%lf", &coeff) == 1))
    {
        while (getchar() != '\n')
            ;
        printf ("# Invalid input\n");
        printf ("# Enter the coefficient ");
        printf("%s", coeff_name);
        printf("\n");
    }
    return coeff;
}

bool end_input (char last_c)
{
    return (last_c == '\n' || last_c == ' ' || last_c == '\t');
}

bool is_equal (double a, double b)
{
    return ((a - b) <= EPS);
}
