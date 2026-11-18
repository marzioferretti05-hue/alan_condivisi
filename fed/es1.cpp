#include <vector>
#include <iostream>
#include <cmath>
#include "lab2_func.h"

using namespace std;

int main(){
	cout<<"--Esercizio 1--"<<endl<<endl;
	
	vector<vector<float>> matrixA = {
		{3, 1, -1, 0},
		{0, 7, -3, 0},
		{0, -3, 9, -2},
		{0, 0, 4, -10}
	};
	
	vector<vector<float>> matrixB = {
		{2, 4, -2, 0},
		{1, 3, 0, 1},
		{3, -1, 1, 2},
		{0, -1, 2, 1},
	};
	
	float norma = normaInf(matrixA);
	cout << "La norma della matrice A è " << norma << endl;
	
	norma = normaInf(matrixB);
	cout << "La norma della matrice B è " << norma << endl;
	
	//matrice di pascal
	int n = 10;
	vector<vector<float>> matrixP = pascal(n);
	printMatrix(matrixP);
	norma = normaInf(matrixP);
	cout << "La norma della matrice di Pascal P è " << norma << endl;
	
	//matrice tridiagonale
	int d0 = 2;
	int d1 = 5;
	n = 10*(d1 + 1) + d0;
	vector<vector<float>> matrixT = triang(n);
	printMatrix(matrixT);
	norma = normaInf(matrixT);
	cout << "La norma della matrice tridiagonale T è " << norma << endl;

	return 0;
}