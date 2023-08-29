#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "solver.h"
#include "colors.h"

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

NumOfSolutions solve_square (Coeffs* coeffs, Complex* x1, Complex* x2)
{
    assert (isfinite (x1->real));
    assert (isfinite (x2->real));
    assert (isfinite (x1->imag));
    assert (isfinite (x2->imag));
    assert (isfinite (coeffs->a));
    assert (isfinite (coeffs->b));
    assert (isfinite (coeffs->c));
    assert (!is_equal (coeffs->a, 0));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    double discr = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c;
    double sqrt_discr = sqrt (fabs(discr));

    if (discr < -EPS)
    {
        x1->real = -(coeffs->b) / 2 / coeffs->a;
        x1->imag = sqrt_discr / 2 / coeffs->a;
        x2->real = x1->real;
        x2->imag = -sqrt_discr / 2 / coeffs->a;
        return TWO_ROOTS;
    }

    if (is_equal (discr, 0))
    {
        x1->real = -(coeffs->b) / 2 / coeffs->a;
        return ONE_ROOT;
    }

    x1->real = (-(coeffs->b) - sqrt_discr) / 2 / coeffs->a;
    x2->real = (-(coeffs->b) + sqrt_discr) / 2 / coeffs->a;
    return TWO_ROOTS;
}

NumOfSolutions solve_equation (Coeffs* coeffs, Complex* x1, Complex* x2)
{
    assert (isfinite (coeffs->a));
    assert (isfinite (coeffs->b));
    assert (isfinite (coeffs->c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (is_equal(coeffs->a, 0))
    {
        return solve_linear (coeffs->b, coeffs->c, x1);
    }
    else
    {
        if (!is_equal (coeffs->b, 0) && is_equal (coeffs->c, 0))
        {
            x1->real = 0;
            x1->imag = 0;
            solve_linear (coeffs->a, coeffs->b, x2);
            return TWO_ROOTS;
        }
        return solve_square (coeffs, x1, x2);
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
    assert (isfinite (x));

    return (is_equal (x, 0)) ? 0 : x;
}

void output_answer (int n_roots, Complex* x1, Complex* x2)
{
    assert (isfinite(x1->real));
    assert (isfinite(x2->real));
    assert (isfinite(x1->imag));
    assert (isfinite(x2->imag));

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
        char str[MAX_LENGTH];
        print_complex (x1, str);
        printf ("1 solution: x = %s", str);
        break;
    case TWO_ROOTS:
        char str1[MAX_LENGTH];
        char str2[MAX_LENGTH];
        print_complex (x1, str1);
        print_complex (x2, str2);
        printf ("2 solutions: x1 = %s, x2 = %s", str1, str2);
        break;
    case INFINIT_ROOTS:
        printf ("Infinite number of solutions");
        break;
    default:
        assert (!"Problem is in the output_answer function");
        break;
    }
}

int print_complex (const Complex* x, char* str)
{
    assert (isfinite (x->real));
    assert (isfinite (x->imag));

    char str_real[MAX_LENGTH];
    char str_imag[MAX_LENGTH];
    char str_zero[] = "0";
    sprintf (str_real, "%.2lf", x->real);
    if (x->imag >= 0)
        sprintf (str_imag, " + %.2lfi", x->imag);
    else
        sprintf (str_imag, " - %.2lfi", fabs(x->imag));

    if (is_equal (x->real, 0))
    {
        strcpy (str_real, str_zero);
        if (is_equal (x->imag, 0))
        {
            strcpy (str, str_zero);
            return 0;
        }
    }
    else if (is_equal (x->imag, 0))
    {
        strcpy (str_imag, str_zero);
        if (is_equal (x->real, 0))
        {
            strcpy (str, str_zero);
            return 0;
        }
    }
    strcat (str_real, str_imag);
    strcpy (str, str_real);
    return 0;
}

void input_coefficients (Coeffs* coeffs)
{
    printf ("# Enter the coefficients a, b, c separated by a space\n");
    while (scanf ("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c)) != 3)
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

void greeting ()
{
    printf (YELLOW_COLOR "# Hello! This program will solve your quadratic equation with complex numbers.\n");
}

void end_of_programm ()
{
    printf(OFF_COLOR "\n");
}
