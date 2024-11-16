#include "Node.h"

using namespace std;

Node::Node()
{
	x = 0;
	y = 0;
	z = 0;
}

Node::Node(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Node& Node::operator=(Node node)
{
	if (&node != this)
	{
		vector<double> vec = node.GetCoordinates();
		this->x = vec[0];
		this->y = vec[1];
		this->z = vec[2];
	}

	return *this;
}

vector<double> Node::GetCoordinates()
{
	return vector<double>{x, y, z};
}

void Node::SetCoordinates(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

bool Node::operator==(const Node& node)
{
	if (node.x == this->x && node.y == this->y && node.z == this->z)
	{
		return true;
	}

	return false;
}
