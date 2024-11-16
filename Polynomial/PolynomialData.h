#include <string>
#include <vector>

using namespace std;

class PolynomialData
{
public:
	PolynomialData(string part);
	PolynomialData(double coefficient, vector<char> variables, vector<double> powers);
	PolynomialData();
	double GetCoefficient();
	vector<char> GetVariables();
	vector<double> GetPowers();
	void Print();
	PolynomialData GetDerivative(char variable);
	PolynomialData GetIntegral(char variable);
	bool operator==(const PolynomialData& data);
	PolynomialData operator+(PolynomialData data);
	PolynomialData operator*(PolynomialData data);
	PolynomialData operator=(PolynomialData data);

private:
	double coefficient;
	vector<char> variables;
	vector<double> powers;
	void CheckZeroValues();


};

