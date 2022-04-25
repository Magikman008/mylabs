#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_LITTLE_VALUE -1
#define SPECIAL_CODE 100

void show_array(const int *arr, const size_t len)
{
    for (size_t j = 0; j < len; j++)
        printf("%d ", *(arr + j));
    puts("");
}

int enter_array(int *arr, size_t *len)
{
    int rc;
    int elem;
    printf("Input your items: ");

    for (size_t i = 0; i < MAX_LEN_OF_ARR + 1; i++)
    {
        rc = scanf("%d", &elem);

        if (rc != EXPECTED_SCANF_RESULT)
            return EXIT_SUCCESS;

        if (i < 10)
        {
            *(arr + i) = elem;
            (*len)++;
        }
    }

    return SPECIAL_CODE;
}

void sort_array(int *arr, const size_t len)
{
    for (size_t i = len - 1; i > 0; i--)
    {
        size_t max_index = 0;
        int cur_max = *(arr);

        for (size_t j = 0; j <= i; j++)
            if (*(arr + j) > cur_max)
            {
                cur_max = *(arr + j);
                max_index = j;
            }

        int temp = *(arr + i);
        *(arr + i) = cur_max;
        *(arr + max_index) = temp;
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    size_t len = 0;

    int arr[MAX_LEN_OF_ARR];
    int rc = enter_array(arr, &len);

    if (len == 0)
    {
        printf("Length of array must be over zero\n");
        return ERROR_TOO_LITTLE_VALUE;
    }

    sort_array(arr, len);
    show_array(arr, len);

    if (rc != EXIT_SUCCESS)
        return SPECIAL_CODE;

    return EXIT_SUCCESS;
}
