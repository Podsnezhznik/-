#pragma once

#include <vector>
#include <iostream>

using namespace std;

class MyVector
{
public:
	void BasicFill();
	void SetSize(int size);
	void PrintVector();
	void ValueFill(double value);
	double SquareNorm();

	MyVector()
	{
		N = 0;
	}

	MyVector(int size)
	{
		N = size;
		vec.resize(N);
	}

	~MyVector()
	{
		vec.clear();
		vec.~vector();
	}

	double& operator [](const int index);
	MyVector operator-(MyVector vector);
	double operator*(MyVector vector);
	MyVector operator*(double scal);
	MyVector operator+(MyVector vector);

private:
	vector<double> vec;
	int N;
};

