#ifndef TESTS_HEADER
#define TESTS_HEADER

const int SIZE_OF_NAME = 25;

struct Test
{
    char name[SIZE_OF_NAME];
    double a;
    double b;
    double c;
    int n_roots;
    double answer1;
    double answer2;
};

void read_file (const char* file_name, struct Test* tests);
void all_tests ();
bool one_test (double a, double b, double c, int n_roots_ref, double x1_ref, double x2_ref);
bool is_equal_test(double a, double b);

#endif
