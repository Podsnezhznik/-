#include "Polynomial.h"
#include "StringManipulations.h"
#include <iostream>


void Polynomial::AddPart(PolynomialData part)
{
	this->polynomParts.push_back(part);
}

void Polynomial::DeleteNullValues()
{
	for (int i = 0; i < this->polynomParts.size(); i++)
	{
		if (this->polynomParts[i].GetCoefficient() == 0)
		{
			this->polynomParts.erase(polynomParts.begin() + i);
			i--;
		}
	}
}

Polynomial::Polynomial(string polynom)
{
	vector<string> polynomParts;
	polynomParts = StringManipulations::SplitOnParts(StringManipulations::DeleteSpaces(polynom), vector<char>{'+', '-'});
	
	for (string s : polynomParts)
	{
		PolynomialData data(s);
		this->polynomParts.push_back(data);
	}
}

Polynomial::Polynomial()
{
}

void Polynomial::Print()
{
	for (auto data : this->polynomParts)
	{
		data.Print();
	}
	cout << endl;
}

Polynomial Polynomial::GetDerivative(char variable)
{
	for (int i = 0; i < this->polynomParts.size(); i++)
	{
		this->polynomParts[i].GetDerivative(variable);
	}

	DeleteNullValues();
	return *this;
}

Polynomial Polynomial::GetIntegral(char variable)
{
	for (int i = 0; i < this->polynomParts.size(); i++)
	{
		this->polynomParts[i].GetIntegral(variable);
	}

	DeleteNullValues();
	return *this;
}

Polynomial Polynomial::operator+(Polynomial polynom)
{
	Polynomial newPolynom = *this;
	Polynomial buffer;

	for (int i = 0; i < newPolynom.polynomParts.size(); i++)
	{
		for (int j = 0; j < polynom.polynomParts.size(); j++)
		{
			if (newPolynom.polynomParts[i] == polynom.polynomParts[j])
			{
				newPolynom.polynomParts[i] = (newPolynom.polynomParts[i] + polynom.polynomParts[j]);
			}
			else
			{
				if (find(buffer.polynomParts.begin(), buffer.polynomParts.end(), polynom.polynomParts[j]) == buffer.polynomParts.end() && 
					find(newPolynom.polynomParts.begin(), newPolynom.polynomParts.end(), polynom.polynomParts[j]) == newPolynom.polynomParts.end())
				{
					buffer.AddPart(polynom.polynomParts[j]);
				}
			}
		}
	}

	for (auto b : buffer.polynomParts)
	{
		newPolynom.AddPart(b);
	}

	newPolynom.DeleteNullValues();
	return newPolynom;
}

Polynomial Polynomial::operator*(Polynomial polynom)
{
	Polynomial newPolynom;

	for (auto item1 : this->polynomParts)
	{
		for (auto item2 : polynom.polynomParts)
		{
			newPolynom.AddPart(item1 * item2);
		}
	}

	newPolynom.DeleteNullValues();
	return newPolynom;
}

Polynomial& Polynomial::operator=(Polynomial& polynom)
{
	this->polynomParts = polynom.polynomParts;

	return *this;
}


