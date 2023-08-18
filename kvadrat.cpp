#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#define POGR 0.00001
int main()
{
    double a, b, c;

    printf("������� ������������ a, b, c\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a <= POGR)
    {
        if (b <= POGR && c <= POGR)
        {
            printf("��������� �� �������� ����������");
        }
        else
        {
            double x = -1 * c / b;
            printf("���� �������: %.5lf", x);
        }
    }
    else
    {
        double des = b*b - 4*a*c;
        if (des < 0)
        {
            printf("��� �������");
        }
        else if (des <= POGR)
        {
            double x = -1 * b / (2*a);
            printf("���� �������: %.5lf", x);
        }
        else
        {
            double x1 = (-1 * b - sqrt(des)) / (2*a);
            double x2 = (-1 * b + sqrt(des)) / (2*a);
            printf("��� �������: %.5lf %.5lf", x1, x2);
        }
    }
}
