#ifndef OUTPUT_COMPLEX_HEADER
#define OUTPUT_COMPLEX_HEADER

struct Complex
{
    double real;
    double imag;
};

enum NumOfSolutions
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINIT_ROOTS = -1
};

void output_answer_complex(int n_roots, const Complex* x1, const Complex* x2);

#endif
