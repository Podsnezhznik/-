#pragma once

#include <vector>
#include "MyVector.h"

using namespace std;

class MyMatrix
{
public:
	MyMatrix(int size)
	{
		N = size;
		matrix.resize(N);
		for (int i = 0; i < N; i++)
		{
			matrix[i].resize(N);
		}
	}

	~MyMatrix()
	{
		for (int i = 0; i < N; i++)
		{
			matrix[i].clear();
			matrix[i].~vector();
		}
		matrix.clear();
		matrix.~vector();
	}

	void CreatePositiveMatrix();
	void PrintMatrix();
	MyVector operator * (MyVector vector);
	double& operator()(int row, int col);

	int GetN()
	{
		return N;
	}

private:
	int N;
	vector<vector<double>> matrix;
};

