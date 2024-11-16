#include <iostream>
#include "Node.h"
#include "Edge.h"
#include "Face.h"
#include "Mesh.h"

using namespace std;

int main()
{
    Mesh mesh;

    mesh.AddFigure(12, 24, 
        0., 0., 0., 
        0., 1., 0., 
        0., 1., 1.,
        0., 0., 1.,
        1., 0., 0.,
        1., 1., 0.,
        1., 1., 1.,
        1., 0., 1.);

    mesh.AddFigure(14, 15,
        0., 0., 1.,
        1., 0., 1.,
        1., 1., 1.,
        0., 1., 1.,
        0.5, 0.5, 2.
    );

    mesh.CreateVTKFile();
}
