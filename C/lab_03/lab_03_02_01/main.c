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

    if (*rows < 2 || *columns < 2)
    {
        puts("Length of array must be over one");
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

int sum_digits(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void find_i_j(int (*matrix)[MAX_LEN_OF_ARR], size_t rows, size_t columns, size_t *return_i, size_t *return_j)
{
    int global_min = sum_digits(abs(*(*(matrix))));
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
        {
            int cur_sum = sum_digits(abs(*(*(matrix + i) + j)));
            if (cur_sum < global_min)
            {
                *return_i = i;
                *return_j = j;
                global_min = cur_sum;
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

void remove_row_and_col(int (*matrix)[MAX_LEN_OF_ARR], size_t *rows, size_t *columns, size_t *return_i, size_t *return_j)
{
    for (size_t i = *return_i; i < *rows - 1; i++)
        for (size_t j = 0; j < *columns; j++)
            *(*(matrix + i) + j) = *(*(matrix + i + 1) + j);
    (*rows)--;

    for (size_t i = 0; i < *rows; i++)
        for (size_t j = *return_j; j < *columns - 1; j++)
            *(*(matrix + i) + j) = *(*(matrix + i) + j + 1);
    (*columns)--;
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

    size_t i = 0, j = 0;
    find_i_j(matrix, rows, columns, &i, &j);
    remove_row_and_col(matrix, &rows, &columns, &i, &j);
    show_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
