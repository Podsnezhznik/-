#pragma once
#include "Face.h"

using namespace std;

Face::Face(const int count, ...)
{
	va_list edges;
	va_start(edges, count);

	for (int i = 0; i < count; i++)
	{
		this->edges.push_back(va_arg(edges, Edge));
	}

	va_end(edges);
}

void Face::SetByCoordinates(const int count, ...)
{
	va_list coordinates;
	va_start(coordinates, count);

	double* edgeCoordinates;

	for (int i = 0; i < count; i += 3)
	{
		edgeCoordinates = new double[6] {va_arg(coordinates, double), va_arg(coordinates, double), va_arg(coordinates, double),
			va_arg(coordinates, double), va_arg(coordinates, double), va_arg(coordinates, double)};

		Node node1(edgeCoordinates[0], edgeCoordinates[1], edgeCoordinates[2]);
		Node node2(edgeCoordinates[3], edgeCoordinates[4], edgeCoordinates[5]);

		Edge edge(node1, node2);

		this->edges.push_back(edge);
	}
}

std::vector<Edge> Face::GetCoordinates()
{
	return this->edges;
}

