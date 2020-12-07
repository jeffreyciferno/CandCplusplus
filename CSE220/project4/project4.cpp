#include <iostream>
#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
	int r = 2;
	int c = 3;
	matrix matrixA(r,c);
	matrix matrixB(r,c);
	matrix matrixC(r,c);
	matrix matrixD(r,c);
	matrix matrixE(r,c);
	matrix matrixF(c,r);
	FILE* m1;
	FILE* m2;

	m1 = fopen(argv[1], "r");
	m2 = fopen(argv[2], "r");
	int variable1 = 0;
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			fscanf(m1,"%d",&variable1);
			matrixA.setValue(i,j,variable1);
		}
	}

	int variable2 = 0;
        for (int i=0; i<r; i++){
                for (int j=0; j<c; j++){
                        fscanf(m2,"%d",&variable2);
                        matrixB.setValue(i,j,variable2);
                }
        }

	cout << "Matrix 1:" << endl;
	cout << matrixA << endl;
	
	cout << "Matrix 2:" << endl;
	cout << matrixB << endl;

	cout << "Transpose m1:" << endl;
	cout << matrixF << endl;

	matrixC = matrixA + matrixB;

	cout << "Add m1 + m2" << endl;
	cout << matrixC << endl;

	matrixD = matrixA * matrixB;	

	cout << "Matrix 1 * Matrix 2" << endl;
        cout << matrixD << endl;

	matrixA = matrixA * 3;

        cout << "Matrix 1 * 3" << endl;
        cout << matrixA << endl;

	matrixE = matrixB;

	cout << "Matrix 3 = Matrix 2" << endl;
        cout << matrixE << endl;
return 0;
}



