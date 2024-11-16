#pragma once
#include<vector>



class Node
{
private:
	double x;
	double y;
	double z;
	
public:
	Node();
	Node(double x, double y, double z);
	Node& operator=(Node node);
	std::vector<double> GetCoordinates();
	void SetCoordinates(double x, double y, double z);
	bool operator==(const Node& node);
};

