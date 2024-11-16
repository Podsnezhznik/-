#include "PolynomialData.h"
#include "StringManipulations.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

PolynomialData::PolynomialData(std::string part)
{
	if (isalpha(part[0]))
	{
		part.insert(0, "1");
	}
	else
	{
		if (isalpha(part[1]))
		{
			part.insert(1, "1");
		}
	}
	this->coefficient = stod(part);

	for (int i = 0; i < part.size(); i ++)
	{
		if (!isalpha(part[i]))
		{
			part.erase(i, 1);
			i--;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < part.size(); i++)
	{
		if (isalpha(part[i]))
		{
			this->variables.push_back((part[i]));
			part.replace(i, 1, 1, ' ');
		}
		else
		{
			if (part[i] == '^')
			{
				part.erase(i, 1);
				i--;
			}
		}
	}

	vector<string> allPowers = StringManipulations::SplitOnPartsBySpaces(part);
	if (allPowers.size() > this->variables.size())
	{
		allPowers.erase(allPowers.begin());
	}
	
	for (string s : allPowers)
	{
		if (s != " ")
		{
			this->powers.push_back(stod(s));
		}
		else
		{
			this->powers.push_back(1);
		}
	}
}

PolynomialData::PolynomialData(double coefficient, vector<char> variables, vector<double> powers)
{
	this->coefficient = coefficient;
	this->powers = powers;
	this->variables = variables;
}

PolynomialData::PolynomialData()
{
}

double PolynomialData::GetCoefficient()
{
	return this->coefficient;
}

vector<char> PolynomialData::GetVariables()
{
	return this->variables;
}

vector<double> PolynomialData::GetPowers()
{
	return this->powers;
}

void PolynomialData::Print()
{
	//int roundedCoefficients = round(coefficient);
	if (coefficient > 0)
	{
		cout << " +";
	}
	cout << ceil(coefficient * 100)/100;

	for (int i = 0; i < variables.size(); i++)
	{
		cout << "(" << variables[i] << "^" << round(powers[i]) << ")";
	}
}

PolynomialData PolynomialData::GetDerivative(char variable)
{
	auto it = find(this->variables.begin(), this->variables.end(), variable);

	if (it == this->variables.end())
	{
		this->coefficient = 0;
	}
	else
	{
		auto index = it - this->variables.begin();
		this->coefficient *= this->powers[index];
		this->powers[index]--;
	}

	this->CheckZeroValues();
	return *this;
}

PolynomialData PolynomialData::GetIntegral(char variable)
{
	auto it = find(this->variables.begin(), this->variables.end(), variable);

	if (it == this->variables.end())
	{
		this->variables.push_back(variable);
		this->powers.push_back(1);
	}
	else
	{
		auto index = it - this->variables.begin();
		this->powers[index] += 1;
		this->coefficient /= this->powers[index];
	}

	this->CheckZeroValues();
	return *this;
}

bool PolynomialData::operator==(const PolynomialData& data)
{
	bool result = true;

	if (this->variables.size() != data.variables.size())
	{
		return false;
	}

	for (int i = 0; i < this->variables.size(); i++)
	{
		if (this->variables[i] != data.variables[i] || this->powers[i] != data.powers[i])
		{
			return false;
		}
	}

	return true;
}

PolynomialData PolynomialData::operator+(PolynomialData data)
{
	PolynomialData result(this->coefficient + data.coefficient, this->variables, this->powers);
	result.CheckZeroValues();
	return result;
}

PolynomialData PolynomialData::operator*(PolynomialData data)
{
	double newCoefficient = this->coefficient * data.coefficient;
	vector<double> newPowers = this->powers;
	vector<char> newVariables = this->variables;

	
	for (int i = 0; i < data.variables.size(); i++)
	{
		auto it{ find(begin(newVariables), end(newVariables), data.variables[i]) };
		if (it != newVariables.end())
		{
			auto index = it - newVariables.begin();
			newPowers[index] += data.powers[i];
		}
		else
		{
			newVariables.push_back(data.variables[i]);
			newPowers.push_back(data.powers[i]);
		}
	}

	PolynomialData newData(newCoefficient, newVariables, newPowers);
	newData.CheckZeroValues();
	return newData;
}

PolynomialData PolynomialData::operator=(PolynomialData data)
{
	this->coefficient = data.coefficient;
	this->variables = data.variables;
	this->powers = data.powers;

	return *this;
}

void PolynomialData::CheckZeroValues()
{
	if (coefficient == 0)
	{
		powers.clear();
		variables.clear();
	}

	for (int i = 0; i < powers.size(); i++)
	{
		if (powers[i] == 0)
		{
			powers.erase(powers.begin() + i);
			variables.erase(variables.begin() + i);
		}
	}

}

