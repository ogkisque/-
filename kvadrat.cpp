#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#define POGR 0.00001
int main()
{
    double a, b, c;

    printf("Введите коэффициенты a, b, c\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a <= POGR)
    {
        if (b <= POGR && c <= POGR)
        {
            printf("Выражение не является уравнением");
        }
        else
        {
            double x = -1 * c / b;
            printf("Одно решение: %.5lf", x);
        }
    }
    else
    {
        double des = b*b - 4*a*c;
        if (des < 0)
        {
            printf("Нет решений");
        }
        else if (des <= POGR)
        {
            double x = -1 * b / (2*a);
            printf("Одно решение: %.5lf", x);
        }
        else
        {
            double x1 = (-1 * b - sqrt(des)) / (2*a);
            double x2 = (-1 * b + sqrt(des)) / (2*a);
            printf("Два решения: %.5lf %.5lf", x1, x2);
        }
    }
}
