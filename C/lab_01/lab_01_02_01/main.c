#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    double a, b, f;
    scanf("%lf%lf%lf", &a, &b, &f);

    double alpha = f * M_PI / 180;
    double s = tan(alpha) * (fabs(a - b) / 2) * ((a + b) / 2);

    printf("%lf\n", s);
    return EXIT_SUCCESS;
}
