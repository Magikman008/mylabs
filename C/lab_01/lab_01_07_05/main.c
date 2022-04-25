#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_VALUE 2
#define ERROR_SCANF 1
#define WRONG_E 2
#define WRONG_X 3


double sum(double x, double e)
{
    double cur = 1;
    int degree = 2;
    double sum = 0;

    while (cur > e)
    {
        sum += cur;
        cur *= x * x * (degree - 1) / degree;
    }
    return sum;
}

int main(void)
{
    double x, e;
    int rc = scanf("%lf%lf", &x, &e);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Wrong input\n");
        return ERROR_SCANF;
    }
    if (e <= 0 || e > 1)
    {
        printf("Wrong input\n");
        return WRONG_E;
    }
    if (fabs(x) >= 1)
    {
        printf("Wrong input\n");
        return WRONG_X;
    }

    double f = 1 / sqrt(1 - x * x);
    double s = sum(x, e);
    double del = fabs(f - s);
    double tet = del / fabs(f);
    printf("%lf %lf %lf %lf", f, s, del, tet);
    return EXIT_SUCCESS;
}
