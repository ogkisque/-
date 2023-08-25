#ifndef TESTS_HEADER
#define TESTS_HEADER
#include "solver.h"
const int SIZE_OF_NAME = 25;

struct Test
{
    char name[30];
    double a;
    double b;
    double c;
    int n_roots;
    double x1_real_ref;
    double x1_imag_ref;
    double x2_real_ref;
    double x2_imag_ref;
};

Test* read_file (const char* file_name, int* num_tests);
void swap (Complex* a, Complex* b);
void all_tests (const char* file_name);
bool is_equal_test(double a, double b);

#endif
