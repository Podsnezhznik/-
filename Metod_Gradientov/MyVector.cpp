#include "MyVector.h"
#include <iostream>

using namespace std;

	void MyVector::BasicFill()
	{
		for (int i = 0; i < N; i++)
		{
			vec[i] = i;
		}
	}

	void MyVector::SetSize(int size)
	{
		N = size;
	}

	void MyVector::PrintVector()
	{
		cout << "(";
		for (int i = 0; i < N - 1; i++)
		{
			cout << vec[i] << " ";
		}
		cout << vec[N - 1] << ")" << "\n";
	}

	void MyVector::ValueFill(double value)
	{
		for (int i = 0; i < N; i++)
		{
			vec[i] = value;
		}
	}

	double MyVector::SquareNorm()
	{
		double result = 0;

		for (int i = 0; i < N; i++)
		{
			result += vec[i] * vec[i];
		}

		return sqrt(result);
	}

	double& MyVector::operator[](const int index)
	{
		return vec[index];
	}

	MyVector MyVector::operator-(MyVector vector)
	{
		MyVector result(N);

		for (int i = 0; i < N; i++)
		{
			result[i] = vec[i] - vector[i];
		}

		return result;
	}

	double MyVector::operator*(MyVector vector)
	{
		double result = 0;

		for (int i = 0; i < N; i++)
		{
			result += vector[i] * vec[i];
		}

		return result;
	}

	MyVector MyVector::operator*(double scal)
	{
		MyVector result(N);

		for (int i = 0; i < N; i++)
		{
			result[i] = vec[i] * scal;
		}

		return result;
	}

	MyVector MyVector::operator+(MyVector vector)
	{
		MyVector result(N);

		for (int i = 0; i < N; i++)
		{
			result[i] = vec[i] + vector[i];
		}
		
		return result;
	}

