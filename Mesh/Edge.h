#pragma once
#include "Node.h"
#include <vector>

class Edge
{
private:
	Node node1;
	Node node2;

public:
	Edge();
	Edge(Node node1, Node node2);
	std::vector<Node> GetCoordinates();
};

