/*!
\file
\brief Header file containing functions for conducting tests of the program
*/

#ifndef TESTS_HEADER
#define TESTS_HEADER

#include "solver.h"

//!< A constant that stores the maximum possible length of the test name
static const int SIZE_OF_NAME = 25;

//! @class Test
//! This structure stores the name of the test, the coefficients a, b, c, the number of roots and the roots themselves
struct Test
{
    char name[SIZE_OF_NAME];
    Coeffs coeffs;
    int n_roots;
    Roots roots;
};

//! @brief Reads tests from a file, counts their number
//! @param const char* file_name - name of file
//! @param int* num_tests - pointer to number of tests
//! @return Test* - array of structures Test read from a file
Test* read_file (const char* file_name, int* num_tests, Errors* error);

//! @brief Swap 2 structures Complex
//! @param Complex* a
//! @param Complex* b
//! @return void
void swap (Complex* a, Complex* b);

void sort_roots (Complex* x1, Complex* x2);

//! @brief Conducts all tests of the program
//! @param const char* file_name - name of file with tests
//! @return void
Errors all_tests (const char* file_name);

//! @brief Compares 2 numbers of the double type
//! @param double a
//! @param double b
//! @return True if the numbers are equal, false if not
bool is_equal_test(const double a, const double b);

void print_failed (const Test* test, const int n_roots, const Complex* x1, const Complex* x2);

void print_ok (const char* name);

void print_end_tests (const int num_ok_tests, const int num_tests);

bool test_is_ok (const int n_roots, const int n_roots_ref, const Complex* x1, const Complex* x2, const Roots* roots);

#endif //TESTS_HEADER
