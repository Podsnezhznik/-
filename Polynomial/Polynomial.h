#include <string>
#include <vector>
#include "PolynomialData.h"

using namespace std;

class Polynomial
{
private:
	vector<PolynomialData> polynomParts;
	void AddPart(PolynomialData part);
	void DeleteNullValues();

public:
	Polynomial(string polynom);
	Polynomial();
	void Print();
	Polynomial GetDerivative(char variable);
	Polynomial GetIntegral(char variable);
	Polynomial operator+(Polynomial polynom);
	Polynomial operator*(Polynomial polynom);
	Polynomial& operator=(Polynomial& polynom);

};

