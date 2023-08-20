#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define POGR 0.00001

int main()
{
    double a, b, c;


    printf("Enter the coefficient a\n");
    while (!(scanf("%lf", &a) == 1 && getchar() == '\n'))
    {
        while (getchar() != '\n');
        printf("Enter the coefficient a\n");
    }
    printf("Enter the coefficient b\n");
    while (!(scanf("%lf", &b) == 1 && getchar() == '\n'))
    {
        while (getchar() != '\n');
        printf("Enter the coefficient b\n");
    }
    printf("Enter the coefficient c\n");
    while (!(scanf("%lf", &b) == 1 && getchar() == '\n'))
    {
        while (getchar() != '\n');
        printf("Enter the coefficient c\n");
    }


    if (a <= POGR)
    {
        if (b <= POGR && c <= POGR)
        {
            printf("The expression is not an equation");
        }
        else
        {
            double x = -1 * c / b;
            printf("One solution: %.5lf", x);
        }
    }
    else
    {
        double des = b*b - 4*a*c;
        if (des < 0)
        {
            printf("No solutions");
        }
        else if (des <= POGR)
        {
            double x = -1 * b / (2*a);
            printf("One solution: %.5lf", x);
        }
        else
        {
            double x1 = (-1 * b - sqrt(des)) / (2*a);
            double x2 = (-1 * b + sqrt(des)) / (2*a);
            printf("Two solutions: %.5lf %.5lf", x1, x2);
        }
    }
}
