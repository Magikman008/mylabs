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

void show_matrix(int (*matrix)[MAX_LEN_OF_ARR], size_t side)
{
    for (size_t i = 0; i < side; i++)
    {
        for (size_t j = 0; j < side; j++)
            printf("%d ", *(*(matrix + i) + j));
        puts("");
    }
    puts("");
}

void input_matrix(int (*matrix)[MAX_LEN_OF_ARR], size_t *side)
{
    *(*(matrix + *side / 2) + *side / 2) = *side * *side;
    (*side)--;
    unsigned int cur_num = 1;
    for (size_t c = 0; c < *side / 2 + 1; c++)
    {
        for (size_t v = c; v < *side - c; v++)
        {
            *(*(matrix + c) + v) = cur_num;
            cur_num++;
        }
        for (size_t v = c; v < *side - c; v++)
        {
            *(*(matrix + v) + *side - c) = cur_num;
            cur_num++;
        }
        for (size_t v = *side - c; v > c; v--)
        {
            *(*(matrix + (*side - c)) + v) = cur_num;
            cur_num++;
        }
        for (size_t v = *side - c; v > c; v--)
        {
            *(*(matrix + v) + c) = cur_num;
            cur_num++;
        }
    }
    (*side)++;
}

int main(void)
{
    size_t side;
    int rc;

    rc = length_input(&side);
    if (rc != EXIT_SUCCESS)
        return rc;

    int matrix[MAX_LEN_OF_ARR][MAX_LEN_OF_ARR];
    input_matrix(matrix, &side);
    show_matrix(matrix, side);

    return EXIT_SUCCESS;
}
