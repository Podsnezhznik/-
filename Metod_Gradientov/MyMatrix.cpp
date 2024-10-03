#include "MyMatrix.h"
#include <iostream>

using namespace std;

void MyMatrix::CreatePositiveMatrix()
{
	const double gamma = 0.00101;

	for (int i = 0; i < N; i++)
	{
		for (int  j = i; j < N; j++)
		{
			matrix[i][j] = gamma * (N * (i + 2) + j + 2);
			matrix[j][i] = gamma * (N * (i + 2) + j + 2);
		}
	}
}

void MyMatrix::PrintMatrix()
{
	for (const auto& row : matrix) {
		for (const auto& col : row) {
			cout << col << "\t";
		}
		cout << endl;
	}
}

MyVector MyMatrix::operator * (MyVector vector)
{
	MyVector result(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i] += matrix[i][j] * vector[j];
		}
	}

	return result;
}

double& MyMatrix::operator()(int row, int col)
{
	return matrix[row][col];
}


