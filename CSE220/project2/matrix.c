#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

 matrix_t *new_matrix(int rows, int cols)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));
    
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * cols * sizeof(int));
   
    return matrix;
}
 void print_matrix(const matrix_t * matrix)
{	int i, j;
    for (i = 0; i < matrix->rows; i++)
    {
        for (j = 0; j < matrix->cols; j++)
        {
            fprintf(stdout, "%d ", get_value(matrix, i, j));
        }
       fprintf(stdout, "\n");
    }
}
 int get_value(const matrix_t * matrix, int row, int col)
{
return *(matrix->data + row * matrix->rows + col);
}
 void set_value(matrix_t * matrix, int row, int col, int value)
{
 *(matrix->data + row * matrix->rows + col) = value;
}
 matrix_t *add(const matrix_t * m1, const matrix_t * m2)
{
    int rows = m1->rows;
    int cols = m1->cols;
    int i, j;
    matrix_t *sum = new_matrix(rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            int matrix1 = get_value(m1, i, j);
            int matrix2 = get_value(m2, i, j);
            set_value(sum, i, j, matrix1 + matrix2);
        }
    }
    return sum;
}
 matrix_t *transpose(const matrix_t * matrix)
{
    int rows = matrix->cols;
    int cols = matrix->rows;
    int i, j;
    matrix_t *transposed = new_matrix(rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            set_value(transposed, i, j, get_value(matrix, j, i));
        }
    }
return transposed;
}
