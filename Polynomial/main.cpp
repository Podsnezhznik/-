#include "Polynomial.h"

void main()
{
	Polynomial p("-4yx^2 + 5x + 3xy");
	Polynomial p1("-4yx^2 + 5y + 3xy + z");
	(p1.GetIntegral('y')).Print();

	/*PolynomialData d1("4yx");
	PolynomialData d2("4zx");

	(d2 * d1).Print();
	(d2 * d1).GetIntegral('x').Print();*/


}