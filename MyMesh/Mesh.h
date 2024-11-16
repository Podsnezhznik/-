#pragma once
#include <vector>
#include <cstdarg>
#include "Node.h"

using namespace std;

class Mesh
{
private:
	vector<vector<int>> cells; //дл€ записи €чеек
	vector<int> cellTypes;
	vector<Node> allNodes;
	int cellsCount;
	int nodesCount;
	int numbersInCellsCount;
	int typesCount;

public:
	void AddFigure(int type, const int count, ...);
	void CreateVTKFile();
	void FillCountValues();
};

