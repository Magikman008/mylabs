#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3
#define ERROR_NOT_SQUARE -4

int length_input(size_t *side)
{
    printf("Input number of rows: ");
    int rc = scanf("%zu", side);

    if (rc != EXPECTED_SCANF_RESULT)
    {
        printf("Wrong input\n");
        return ERROR_WRONG_INPUT;
    }

    size_t columns;
    printf("Input number of columns: ");
    rc = scanf("%zu", &columns);

    if (rc != EXPECTED_SCANF_RESULT)
    {
        printf("Wrong input\n");
        return ERROR_WRONG_INPUT;
    }

    if (*side < 1 || columns < 1)
    {
        printf("Length of array must be over zero\n");
        return ERROR_TOO_LITTLE_VALUE;
    }
    if (*side > MAX_LEN_OF_ARR || columns > MAX_LEN_OF_ARR)
    {
        printf("Length of array must be under or equal ten\n");
        return ERROR_TOO_BIG_VALUE;
    }

    if (*side != columns)
    {
        puts("Numner of rows and columns must be equal");
        return ERROR_NOT_SQUARE;
    }
    return EXIT_SUCCESS;
}

int input_arr(int (*matrix)[MAX_LEN_OF_ARR], size_t side)
{
    int rc;
    puts("Input your items: ");
    for (size_t i = 0; i < side; i++)
        for (size_t j = 0; j < side; j++)
        {
            rc = scanf("%d", (*(matrix + i) + j));
            if (rc != EXPECTED_SCANF_RESULT)
            {
                printf("Wrong input\n");
                return ERROR_WRONG_INPUT;
            }
        }
    return EXIT_SUCCESS;
}

void replace_rows(int (*matrix)[MAX_LEN_OF_ARR], size_t side)
{
    for (size_t i = 0; i < side / 2; i++)
        for (size_t j = i; j < side - i; j++)
        {
            int temp = *(*(matrix + side - i - 1) + j);
            *(*(matrix + side - i - 1) + j) = *(*(matrix + i) + j);
            *(*(matrix + i) + j) = temp;
        }
}

void show_matrix(int (*matrix)[MAX_LEN_OF_ARR], size_t side)
{
    for (size_t i = 0; i < side; i++)
    {
        for (size_t j = 0; j < side; j++)
            printf("%d ", *(*(matrix + i) + j));
        puts("");
    }
}

int main(void)
{
    size_t side;
    int rc = length_input(&side);

    if (rc != EXIT_SUCCESS)
        return rc;

    int matrix[MAX_LEN_OF_ARR][MAX_LEN_OF_ARR];
    rc = input_arr(matrix, side);
    if (rc != EXIT_SUCCESS)
        return rc;

    replace_rows(matrix, side);
    show_matrix(matrix, side);
    return EXIT_SUCCESS;
}
