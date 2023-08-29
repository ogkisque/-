#include <stdio.h>
#include <string.h>
#include <math.h>
#include "solver.h"
#include "tests.h"

int main (int argc, char* argv[])
{
    const char* FLAG_TESTS = "--tests";
    if ((argc == 3) && (strcmp(argv[1], FLAG_TESTS) == 0))
    {
        Errors err = all_tests (argv[2]);
        switch (err)
        {
        case ERROR_FILE_OPEN:
            printf ("There is no such file\n");
            break;
        case ERROR_OF_MEMORY:
            printf ("Insufficient memory\n");
            break;
        default:
            break;
        }
        return 0;
    }

    greeting ();
    Coeffs coeffs = {.a = NAN, .b = NAN, .c = NAN};
    input_coefficients (&coeffs);

    Complex x1 = {.real = 0, .imag = 0};
    Complex x2 = {.real = 0, .imag = 0};
    int n_roots = solve_equation (&coeffs, &x1, &x2);

    output_answer (n_roots, &x1, &x2);
    end_of_programm ();
    return 0;
}
