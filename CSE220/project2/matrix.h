#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix_t
{
    int rows;
    int cols;
    int *data;
}
matrix_t;
 matrix_t *new_matrix(int rows, int cols);
 void print_matrix(const matrix_t * matrix);
 int get_value(const matrix_t * matrix, int row, int col);		 
 void set_value(matrix_t * matrix, int row, int col, int value);
 matrix_t *add(const matrix_t * m1, const matrix_t * m2);
 matrix_t *transpose(const matrix_t * matrix);

#endif

