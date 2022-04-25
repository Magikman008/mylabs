#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN_OF_ARR 10
#define EXPECTED_SCANF_RESULT 1
#define ERROR_TOO_BIG_VALUE -1
#define ERROR_TOO_LITTLE_VALUE -2
#define ERROR_WRONG_INPUT -3

int length_input(size_t *rows, size_t *columns)
{
    printf("Input number of rows: ");
    int rc = scanf("%zu", rows);

    if (rc != EXPECTED_SCANF_RESULT)
    {
        puts("Wrong input");
        return ERROR_WRONG_INPUT;
    }

    printf("Input number of columns: ");
    rc = scanf("%zu", columns);

    if (rc != EXPECTED_SCANF_RESULT)
    {
        puts("Wrong input");
        return ERROR_WRONG_INPUT;
    }

    if (*rows < 1 || *columns < 1)
    {
        puts("Length of array must be over zero");
        return ERROR_TOO_LITTLE_VALUE;
    }
    if (*rows > MAX_LEN_OF_ARR || *columns > MAX_LEN_OF_ARR)
    {
        puts("Length of array must be under or equal ten");
        return ERROR_TOO_BIG_VALUE;
    }

    return EXIT_SUCCESS;
}

int input_arr(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns)
{
    int rc;
    puts("Input your items: ");
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
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

int find_max_in_arr(int *arr, size_t len)
{
    int max = *(arr);
    for (size_t i = 1; i < len; i++)
        if (*(arr + i) > max)
            max = *(arr + i);
    return max;
}

void sort_matrix(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < rows - i - 1; j++)
        {
            if (find_max_in_arr(*(matrix + j), columns) < find_max_in_arr(*(matrix + j + 1), columns))
            {
                for (size_t c = 0; c < columns; c++)
                {
                    int temp = *(*(matrix + j) + c);
                    *(*(matrix + j) + c) = *(*(matrix + j + 1) + c);
                    *(*(matrix + j + 1) + c) = temp;
                }
            }
        }
}

void show_matrix(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            printf("%d ", *(*(matrix + i) + j));
        puts("");
    }
}

int main(void)
{
    size_t rows;
    size_t columns;
    int rc = length_input(&rows, &columns);

    if (rc != EXIT_SUCCESS)
        return rc;

    int matrix[MAX_LEN_OF_ARR][MAX_LEN_OF_ARR];
    rc = input_arr(matrix, rows, columns);
    if (rc != EXIT_SUCCESS)
        return rc;

    sort_matrix(matrix, rows, columns);
    show_matrix(matrix, rows, columns);
    return EXIT_SUCCESS;
}
