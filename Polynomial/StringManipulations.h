#include <vector>
#include <string>

using namespace std;

class StringManipulations
{
public:
	static vector<string> SplitOnParts(string polynom, vector<char> symbols);
	static vector<string> SplitOnPartsBySpaces(string polynom);
	static string DeleteSpaces(string polynom);
};

