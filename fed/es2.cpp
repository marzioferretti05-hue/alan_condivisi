#include <vector>
#include <iostream>
#include <cmath>
#include "lab2_func.h"

using namespace std;

int main(){
	//creazione matrici di supporto
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

	//matrice di pascal
	int n = 10;
	vector<vector<float>> matrixP = pascal(n);

	//matrice tridiagonale
	int d0 = 2;
	int d1 = 5;
	n = 10*(d1 + 1) + d0;
	vector<vector<float>> matrixT = triang(n);
	
	//es2
	es2(matrixA, 'A');
	es2(matrixB, 'B');
	es2(matrixP, 'P');
	es2(matrixT, 'T');
	
	return 0;
}