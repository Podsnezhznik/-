#include "Mesh.h"
#include <iostream>
#include <fstream>

using namespace std;

void Mesh::AddFigure(int type, const int count, ...)
{
	if (count % 3 != 0)
	{
		cout << "Неверный ввод данных!" << endl;
		return;
	}

	va_list allCoordinates;
	va_start(allCoordinates, count);

	vector<Node> nodes;
	vector<int> currentCell;

	currentCell.push_back(count / 3);

	for (int i = 0; i < count; i += 3)
	{
		double c1 = va_arg(allCoordinates, double);
		double c2 = va_arg(allCoordinates, double);
		double c3 = va_arg(allCoordinates, double);

		Node node(c1, c2, c3);

		nodes.push_back(node);

		auto it = find(allNodes.begin(), allNodes.end(), node);
		if (it != allNodes.end())
		{
			currentCell.push_back(it - allNodes.begin());
		}
		else
		{
			allNodes.push_back(node);
			currentCell.push_back(allNodes.size() - 1);
		}
	}

	va_end(allCoordinates);

	cellTypes.push_back(type);

	cells.push_back(currentCell);
}

void Mesh::CreateVTKFile()
{
	ofstream out;
	out.open("test.vtk");

	out << "# vtk DataFile Version 3.0.\ncomment\nASCII\nDATASET UNSTRUCTURED_GRID\n";

	FillCountValues();

	out << "POINTS " << nodesCount << " float" << endl;

	for (auto node : allNodes)
	{
		auto point = node.GetCoordinates();

		out << point[0] << " " << point[1] << " " << point[2] << endl;
	}

	out << "CELLS " << cellsCount << " " << numbersInCellsCount << endl;

	for (auto cell : cells)
	{
		for (int value : cell)
		{
			out << value << " ";
		}
		out << endl;
	}

	out << "CELL_TYPES " << cellTypes.size() << endl;

	for (auto type : cellTypes)
	{
		out << type << endl;
	}
}

void Mesh::FillCountValues()
{
	this->typesCount = cellTypes.size();
	this->cellsCount = cells.size();
	this->nodesCount = allNodes.size();
	
	for (auto item : cells)
	{
		this->numbersInCellsCount += item.size();
	}
}
