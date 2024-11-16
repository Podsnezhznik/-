#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Face.h"

using namespace std;

int main()
{
    Node n1(1,2,3), n2(4,5,6), n3(7,8,9);

    Edge e1(n1, n2), e2(n2, n3);

    Face f1(2, e1, e2);
}
