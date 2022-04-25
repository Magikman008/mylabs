#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3
#define ERROR_CANT_SOLVE -4

int enter_array(int *arr, const size_t len)
{
    int rc;
    int count = 0;
    printf("Input your items: ");

    for (size_t i = 0; i < len; i++)
    {
        rc = scanf("%d", (arr + i));

        if (rc != EXPECTED_SCANF_RESULT)
        {
            printf("Wrong input\n");
            return ERROR_WRONG_INPUT;
        }

        if (abs(*(arr + i) % 2) == 1)
            count++;
    }

    if (count == 0)
    {
        printf("You must enter more then zero odd numbers\n");
        return ERROR_CANT_SOLVE;
    }

    return EXIT_SUCCESS;
}

void multiply_of_odd(int *arr, const size_t len, int *mult)
{
    for (size_t i = 0; i < len; i++)
    {
        if (abs(*(arr + i) % 2) == 1)
            *mult *= *(arr + i);
    }
}

int input_length(size_t *len)
{
    printf("Input length of array: ");
    int rc = scanf("%zu", len);

    if (rc != EXPECTED_SCANF_RESULT)
    {
        printf("Wrong input\n");
        return ERROR_WRONG_INPUT;
    }

    if (*len < 1)
    {
        printf("Length of array must be over zero\n");
        return ERROR_TOO_LITTLE_VALUE;
    }

    if (*len > MAX_LEN_OF_ARR)
    {
        printf("Length of array must be under or equal ten\n");
        return ERROR_TOO_BIG_VALUE;
    }

    return EXIT_SUCCESS;
}

int main(void)
{
    setbuf(stdout, NULL);

    size_t len;
    int rc;

    if ((rc = input_length(&len)) != EXIT_SUCCESS)
        return rc;

    int arr[MAX_LEN_OF_ARR];

    if ((rc = enter_array(arr, len)) != EXIT_SUCCESS)
        return rc;

    int mult = 1;
    multiply_of_odd(arr, len, &mult);
    printf("Answer is %d\n", mult);

    return EXIT_SUCCESS;
}
