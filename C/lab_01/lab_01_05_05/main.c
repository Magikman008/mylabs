#include <stdio.h>
#include <stdlib.h>

#define EXPECTED_SCANF_VALUE 1
#define ERROR_SCANF 1
#define ERROR_NUM 2

void show(int x)
{
    int tmp = 1;
    while (tmp <= x / 10)
    {
        tmp *= 10;
    }
    while (tmp > 0)
    {
        printf("%d", x / tmp);
        x %= tmp;
        tmp /= 10;
    }
    printf("\n");
}

int main()
{
    int n;
    int rc = scanf("%d", &n);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Wrong input\n");
        return ERROR_SCANF;
    }

    if (n <= 0)
    {
        printf("Wrong input\n");
        return ERROR_NUM;
    }

    show(n);

    return EXIT_SUCCESS;
}
