/*!
\file
\brief Header file containing functions for conducting tests of the program
*/

#ifndef TESTS_HEADER
#define TESTS_HEADER
#include "solver.h"

//!< A constant that stores the maximum possible length of the test name
const int SIZE_OF_NAME = 25;

//! @class Test
//! This structure stores the name of the test, the coefficients a, b, c, the number of roots and the roots themselves
struct Test
{
    char name[SIZE_OF_NAME];
    double a;
    double b;
    double c;
    int n_roots;
    double x1_real_ref;
    double x1_imag_ref;
    double x2_real_ref;
    double x2_imag_ref;
};

//! @brief Reads tests from a file, counts their number
//! @param const char* file_name - name of file
//! @param int* num_tests - pointer to number of tests
//! @return Test* - array of structures Test read from a file
Test* read_file (const char* file_name, int* num_tests);

//! @brief Swap 2 structures Complex
//! @param Complex* a
//! @param Complex* b
//! @return void
void swap (Complex* a, Complex* b);

//! @brief Conducts all tests of the program
//! @param const char* file_name - name of file with tests
//! @return void
void all_tests (const char* file_name);

//! @brief Compares 2 numbers of the double type
//! @param double a
//! @param double b
//! @return True if the numbers are equal, false if not
bool is_equal_test(double a, double b);

#endif
