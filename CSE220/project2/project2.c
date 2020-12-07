#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"


int main(int argc, char *argv[]){
int row, col, i, j, variable1, variable2;
matrix_t * matrix1;
matrix_t * matrix2;
FILE* m1;
FILE* m2;
row = 2;
col = 3;
m1 = fopen(argv[1], "r");
m2 = fopen(argv[2], "r");
variable1 = 0;
printf("Read A from file matrix1.txt:");
matrix1 = new_matrix(row, col);

for(i = 0; i < row; i++)
  {
    for (j = 0 ; j < col; j++)
    {
      fscanf(m1,"%d",&variable1);
      set_value(matrix1, i, j, variable1);
    }
    printf("\n");
}
print_matrix(matrix1);
printf("\n");
printf("Read B from file matrix1.txt:");
matrix2 = new_matrix(row, col);
for(i = 0; i < row; i++)
  {
    for (j = 0 ; j < col; j++)
    {
      fscanf(m2,"%d",&variable2);
      set_value(matrix2, i, j, variable2);
    }
    printf("\n");
}
print_matrix(matrix2);
printf("\n");
printf("C = A + B: \n");
printf("\n");
print_matrix(add(matrix1, matrix2));
printf("\n");
printf("D = Transpose A: \n");
printf("\n");
print_matrix(transpose(matrix1));



return 0;
}

