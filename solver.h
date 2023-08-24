#ifndef SOLVER_HEADER
#define SOLVER_HEADER

const double EPS = 1e-8;

enum NumOfSolutions
{
    INFINIT_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2
};

NumOfSolutions solve_equation (double a, double b, double c, double* x1, double* x2);
NumOfSolutions solve_linear (double a, double b, double* x);
NumOfSolutions solve_square (double a, double b, double c, double* x1, double* x2);
bool is_equal (double a, double b);


#endif
