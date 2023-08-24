#ifndef SOLVER_COMPLEX_HEADER
#define SOLVER_COMPLEX_HEADER

#include "output_complex.h"
#include "solver.h"

NumOfSolutions solve_linear_complex (double a, double b, Complex* x);
NumOfSolutions solve_square_complex (double a, double b, double c, Complex* x1, Complex* x2);
NumOfSolutions solve_equation_complex (double a, double b, double c, Complex* x1, Complex* x2);

#endif
