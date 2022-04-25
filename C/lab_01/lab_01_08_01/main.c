#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_VALUE 4
#define ERROR_SCANF 1
#define BITS 8

void show(unsigned x)
{
    for (int i = 0; i < BITS; i++)
    {
        unsigned bit = (x >> (7 - i)) & 1;
        printf("%u", bit);
    }
}

int main(void)
{
    unsigned x1, x2, x3, x4;

    int rc = scanf("%u%u%u%u", &x1, &x2, &x3, &x4);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Error: %d", ERROR_SCANF);
        return EXIT_FAILURE;
    }

    printf("Result: ");
    show(x1);
    show(x2);
    show(x3);
    show(x4);
    printf(" %u %u %u %u", x1, x2, x3, x4);
    return EXIT_SUCCESS;
}
