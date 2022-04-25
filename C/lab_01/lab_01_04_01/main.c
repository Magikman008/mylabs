#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double num;
    scanf("%lf", &num);

    double entrance = floor((num + 35) / 36);
    double floor = (int)((num - ((entrance - 1) * 36) + 3) / 4);

    printf("%lf %lf\n", entrance, floor);
    return EXIT_SUCCESS;
}
