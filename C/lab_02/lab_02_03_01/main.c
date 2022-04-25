#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN_OF_ARR 20
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3
#define ERROR_CANT_SOLVE -4

int enter_array(int *arr, const size_t len)
{
    int rc;
    printf("Input your items: ");

    for (size_t i = 0; i < len; i++)
    {
        rc = scanf("%d", &arr[i]);

        if (rc != EXPECTED_SCANF_RESULT)
        {
            printf("Wrong input\n");
            return ERROR_WRONG_INPUT;
        }
    }

    return EXIT_SUCCESS;
}

void insert_fib_to_arr(int *arr, const size_t len, const size_t cur_i)
{
    for (size_t i = len - 1; i > cur_i; i--)
        *(arr + i) = *(arr + i - 1);
}

void find_numbers_divisible(int *arr, size_t *len)
{
    size_t i = 0;
    int prev_f = 0;
    int cur_f = 0;
    int temp;

    while (i < *len)
    {
        if (*(arr + i) % 3 == 0)
        {
            insert_fib_to_arr(arr, *len + 1, i);
            *len = *len + 1;
            *(arr + i + 1) = cur_f;
            i += 2;

            if (cur_f == 0 && prev_f == 0)
                cur_f = 1;
            else
            {
                temp = cur_f;
                cur_f += prev_f;
                prev_f = temp;
            }
        }
        else
            i++;
    }
}

int input_len(size_t *len)
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

    if ((rc = input_len(&len)) != EXIT_SUCCESS)
        return rc;

    int arr[MAX_LEN_OF_ARR];

    if ((rc = enter_array(arr, len)) != EXIT_SUCCESS)
        return rc;

    find_numbers_divisible(arr, &len);

    for (size_t i = 0; i < len; i++)
        printf("%d ", *(arr + i));
    puts("");

    return EXIT_SUCCESS;
}
