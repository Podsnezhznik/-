#include "StringManipulations.h"

vector<string> StringManipulations::SplitOnParts(string polynom, vector<char> symbols)
{
	string part = "";
	vector<string> result;
	bool go = false;
	for (int i = 0; i < polynom.length(); i++)
	{
		part += polynom[i];

		for (int j = 0; (j < symbols.size()); j++)
		{
			if (i == polynom.length() - 1 || polynom[i + 1] == symbols[j])
			{
				go = true;
			}
		}

		if (go && i > 1)
		{
			result.push_back(part);
			part = "";
		}

		go = false;
	}

	return result;
}

vector<string> StringManipulations::SplitOnPartsBySpaces(string polynom)
{
	string part = "";
	vector<string> result;
	bool go = false;
	for (int i = 0; i < polynom.length(); i++)
	{
		part += polynom[i];

		if (i == polynom.length() - 1 || polynom[i + 1] == ' ')
		{
			go = true;
		}

		if (go)
		{
			result.push_back(part);
			part = "";
		}

		go = false;
	}

	return result;
}

string StringManipulations::DeleteSpaces(string polynom)
{
	string result;

	for (char c : polynom)
	{
		if (c != ' ')
		{
			result += c;
		}
	}

	return result;
}