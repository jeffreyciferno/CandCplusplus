#include "matrix.h"
#include <iostream>

using namespace std;


matrix::matrix(int r, int c){           
	row = r;
	col = c;
	array = new int*[row];             

	for (int i=0; i<row; i++){
		array[i] = new int[col];      
		}

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			array[i][j] = 0;            
		}
	}
}

matrix::matrix(const matrix& m){ 
	row = m.row;
	col = m.col;
	array = new int*[row];
	for (int i=0; i<row; i++){
		array[i] = new int[col];
		}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			array[i][j] = m.array[i][j];
		}
	}
}

matrix::~matrix(){ 
	for (int i=0; i<row; i++){
		delete[] array[i]; 
		}
	delete[] array; 
	}

matrix matrix::transpose(const matrix& m){
	row = m.col;
	col = m.row;
       	for (int i=0; i<row; i++){
               for (int j=0; j<col; j++){
                       array[i][j] = m.array[i][j];
                }
        }
	return m;
}


void matrix::setValue(int r, int c, int e){
	array[r][c] = e;
}

int matrix::getValue(int r, int c){
	return array[r][c];
}



matrix matrix::operator=(const matrix& m){

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
              array[i][j] = m.array[i][j];
            }
        }
        return m;
     }

matrix matrix::operator+(const matrix& m){
	matrix new_mat(row,col);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			new_mat.array[i][j] = array[i][j] + m.array[i][j];
		}
	}
	return new_mat;
}

matrix matrix::operator*(const matrix& m){

	matrix new_mat(row,col);
	for (int i=0; i<row; i++){  
		for (int j=0; j<col; j++){  
            
                new_mat.array[i][j] = array[i][j] * m.array[i][j];
            }
		}
	
	return new_mat;
}

matrix matrix::operator*(const int &num){

        matrix new_mat(row,col);
        for (int i=0; i<row; i++){ 
                for (int j=0; j<col; j++){  
            
	new_mat.array[i][j] = array[i][j] * num;
            }
                }
        
        return new_mat;
}


