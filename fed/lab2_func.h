#ifndef ES1_FUNC_GH
#define ES1_FUNC_GH

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<vector<float>> flipVector(const vector<vector<float>> &v);

float normaInf(vector<vector<float>> a);

float factorial(float N);

void printMatrix(const vector<vector<float>> &a);

vector<vector<float>> pascal(const int &n);

vector<vector<float>> triang(const int &n);

vector<vector<float>> moltMatrix(const vector<vector<float>> &a, const vector<vector<float>> &b);

void swap(float &a, float &b);

void scambioRighe(vector<vector<float>> &a, int x, int y);

vector<vector<float>> gauss(vector<vector<float>> a);

void matrixFuseGauss(vector<vector<float>> &m, vector<vector<float>> &v);

vector<vector<float>> sostituzioneIndietro(const vector<vector<float>> &m, const vector<vector<float>> &v);

void es2(vector<vector<float>> matrixM, char n);

void es3(vector<vector<float>> matrixM, char n);

#endif