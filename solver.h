/*!
\file
\brief Header file containing functions for solving a quadratic equation and data input and output
*/

#ifndef SOLVER_HEADER
#define SOLVER_HEADER

//! @class Complex
//! This structure stores the real and imaginary parts of a complex number
struct Complex
{
    double real;
    double imag;
};

struct Coeffs {
    double a;
    double b;
    double c;
};

struct Roots {
    Complex x1;
    Complex x2;
};

enum Errors
{
    CORRECT             = 0,
    ERROR_FILE_OPEN     = 1,
    ERROR_OF_MEMORY     = 2
};

//! This enum stores all possible numbers of solutions to the quadratic equation
enum NumOfSolutions
{
    INFINIT_ROOTS   = -1,
    NO_ROOTS        = 0,
    ONE_ROOT        = 1,
    TWO_ROOTS       = 2,
};

const int MAX_LENGTH = 20;

//! @brief Solves a linear equation
//! @param double a - the first coefficient
//! @param double b - the second coefficient
//! @param Complex* x - pointer to answer
//! @return Number of solutions
NumOfSolutions solve_linear (double a, double b, Complex* x);

//! @brief Solves a square equation with a non-zero coefficient a
//! @param double a - the first coefficient
//! @param double b - the second coefficient
//! @param double c - the third coefficient
//! @param Complex* x1 - pointer to the first answer
//! @param Complex* x2 - pointer to the second answer
//! @return Number of solutions
NumOfSolutions solve_square (Coeffs* coeffs, Complex* x1, Complex* x2);

//! @brief Solves a square equation
//! @param double a - the first coefficient
//! @param double b - the second coefficient
//! @param double c - the third coefficient
//! @param Complex* x1 - pointer to the first answer
//! @param Complex* x2 - pointer to the second answer
//! @return Number of solutions
NumOfSolutions solve_equation (Coeffs* coeffs, Complex* x1, Complex* x2);

//! @brief Compares 2 numbers of the double type
//! @param double a
//! @param double b
//! @return True if the numbers are equal, false if not
bool is_equal (double a, double b);

//! @brief Convert the number -0.0000 to 0.0000
//! @param double x
//! @return 0.0000 if x = -0.0000, and x if not
double make_negative_zero (double x);

//! @brief Prints the response
//! @param int n_roots - number of roots
//! @param Complex* x1 - pointer to the first answer
//! @param Complex* x2 - pointer to the second answer
//! @return void
void output_answer (int n_roots, Complex* x1, Complex* x2);

//! @brief Prints a complex number
//! @param Complex* x - pointer to output Complex number
//! @return void
int print_complex (const Complex* x, char* str);

//! @brief Enters the coefficients of the square equation
//! @param double* a - pointer to the first coefficient
//! @param double* b - pointer to the second coefficient
//! @param double* c - pointer to the third coefficient
//! @return void
void input_coefficients (Coeffs* coeffs);

//! @brief Clear buffer contents
//! @return void
void clear_buffer ();

void greeting ();

void end_of_programm ();

#endif //SOLVER_HEADER
