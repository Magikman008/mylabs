#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_VALUE 8
#define ERROR_SCANF 1
#define WRONG_CORDS 1
#define EPS 1e-5

#define NOT_CROSSES 0
#define CROSSES 1

double vector(double vx1, double vy1, double vx2, double vy2)
{
    return vx1 * vy2 - vx2 * vy1;
}

int check_crosses(double x1, double y1, double x2, double y2, double x3, double y3,
double x4, double y4)
{
    double v1 = vector(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
    double v2 = vector(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
    double v3 = vector(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    double v4 = vector(x2 - x1, y2 - y1, x4 - x1, y4 - y1);

    return ((v1 * v2 < 0) && (v3 * v4 < 0));
}

int main(void)
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    int rc = scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Wrong input\n");
        return ERROR_SCANF;
    }
    if ((fabs(x1 - x2) < EPS && fabs(y1 - y2) < EPS) || (fabs(x3 - x4) < EPS && fabs(y3 - y4) < EPS))
    {
        printf("Wrong input\n");
        return WRONG_CORDS;
    }

    printf("%d", check_crosses(x1, y1, x2, y2, x3, y3, x4, y4));
    return EXIT_SUCCESS;
}
