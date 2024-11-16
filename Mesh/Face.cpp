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

std::vector<Edge> Face::GetCoordinates()
{
	return std::vector<Edge>();
}

