#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

class matrix
{
	int row;
	int col;
	int **array;

	public:
		matrix(int,int);
		matrix(const matrix&); 
		~matrix();
		matrix transpose(const matrix&); 
		matrix operator=(const matrix&);
		matrix operator+(const matrix&);
		matrix operator*(const matrix&);
		matrix operator*(const int &num);
	
	friend std::ostream &operator<<(std::ostream &os, const matrix &m) {
	for (int i=0; i < m.row; ++i) {
                for (int j=0; j < m.col; ++j) {
                    os << m.array[i][j] << "  " ;
                }
                os << '\n';
            }
            return os;

	}


        void setValue(int r, int c, int e);
		int getValue(int r, int c);
};

#endif
