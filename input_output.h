#ifndef IO_HEADER
#define IO_HEADER

/*
enum NumOfSolutions
{
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    INFINIT_ROOTS = -1
};
*/

void input_double (double* a, double* b, double* c);
void clear_buffer ();
void output_answer (int n_roots, double x1, double x2);

#endif
