#include "Edge.h"

using namespace std;

Edge::Edge()
{
	node1.SetCoordinates(0, 0, 0);
	node2.SetCoordinates(0, 0, 0);
}

Edge::Edge(Node node1, Node node2)
{
	this->node1 = node1;
	this->node2 = node2;
}

std::vector<Node> Edge::GetCoordinates()
{
	return std::vector<Node>{node1, node2};
}


