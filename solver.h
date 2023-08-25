#ifndef SOLVER_HEADER
#define SOLVER_HEADER

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


NumOfSolutions solve_linear (double a, double b, Complex* x);
NumOfSolutions solve_square (double a, double b, double c, Complex* x1, Complex* x2);
NumOfSolutions solve_equation (double a, double b, double c, Complex* x1, Complex* x2);
bool is_equal (double a, double b);

double make_negative_zero (double x);
void output_answer(int n_roots, Complex* x1, Complex* x2);
void print_complex (Complex* x);
void input_double (double* a, double* b, double* c);
void clear_buffer ();

#endif
