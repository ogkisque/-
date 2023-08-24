#ifndef SOLVER_HEADER
#define SOLVER_HEADER

#include "output_complex.h"

NumOfSolutions solve_equation (double a, double b, double c, double* x1, double* x2);
NumOfSolutions solve_linear (double a, double b, double* x);
NumOfSolutions solve_square (double a, double b, double c, double* x1, double* x2);
bool is_equal (double a, double b);

#endif
