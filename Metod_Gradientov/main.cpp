#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"

using namespace std;

const int N = 10;

static MyVector Calculate(MyMatrix A, MyVector x0, MyVector b);

int main()
{
	MyMatrix A(N);

	A.CreatePositiveMatrix();

	A.PrintMatrix();

	MyVector x0(N);

	x0.ValueFill(0);

	x0.PrintVector();

	MyVector x(N);

	x.BasicFill();

	x.PrintVector();

	MyVector b = A * x;

	Calculate(A, x0, b).PrintVector();
}

static MyVector Calculate(MyMatrix A, MyVector x0, MyVector b)
{
	MyVector x_k = x0;

	MyVector r_k = b - A * x0;

	MyVector p_k = r_k;

	MyVector x_kp1, r_kp1, p_kp1;

	double eps = 0.0000001;

	double alpha_k, betta_k;

	while (true)
	{
		alpha_k = -(r_k * r_k) / (p_k * (A * p_k));

		x_kp1 = x_k - p_k * alpha_k;

		MyVector buffer = ((A * p_k) * alpha_k);
		r_kp1 = r_k + buffer;

		if (r_kp1.SquareNorm() < eps)
		{
			break;
		}

		betta_k = (r_kp1 * r_kp1) / (r_k * r_k);

		p_kp1 = r_kp1 + p_k * betta_k;

		p_k = p_kp1;
		r_k = r_kp1;
		x_k = x_kp1;
	}

	return x_k;
}