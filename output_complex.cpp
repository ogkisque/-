#include <stdio.h>
#include <assert.h>
#include "output_complex.h"

void output_answer_complex(int n_roots, const Complex* x1, const Complex* x2)
{
    switch (n_roots)
    {
    case NO_ROOTS:
        printf ("No solutions");
        break;
    case ONE_ROOT:
        printf ("1 solution: %.5lf %.5lfi", x1->real, x1->imag);
        break;
    case TWO_ROOTS:
        printf ("2 solutions: %.5lf %.5lfi, %.5lf %.5lfi", x1->real, x1->imag, x2->real, x2->imag);
        break;
    case INFINIT_ROOTS:
        printf ("Infinite number of solutions");
        break;
    default:
        assert (!"Problem is in the output_answer function");
        break;
    }
}
