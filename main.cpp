#include <iostream>
#include "Environment.h"
#include "RedHood.h"
#include "Granny.h"
#include "Graph.h"

#define Max(a, b) (a>b?a:b)
using namespace std;

int main() {

    Environment environment;
    environment.UpdateUnitsPositions();

    Granny granny("Granny");
    RedHood redHood("RedHood");
    environment.AddUnit(redHood);
    environment.AddUnit(granny);
    unsigned int a, b;
    a = 2;
    b = 3;
    granny.SetPosition(a - 1, b - 1);
    a = 1;
    b = 1;
    redHood.SetPosition(a - 1, b - 1);
    cout << endl << endl << endl;
    environment.UpdateUnitsPositions();

    Graph<pair<int,int>> graph;
    typedef pair<int,int> point;

    for (int i = 0; i < environment.GetSize(); i++) {
        for (int j = 0; j < environment.GetSize(); j++) {
            graph.AddVertex(point(i,j));
        }
    }


   for (int i = 0; i < environment.GetSize(); i++) {
        for (int j = 0; j < environment.GetSize(); j++) {
            if (i - 1 >= 0) graph.AddEdge(point(i, j), point(i - 1, j));
            if (i + 1 < environment.GetSize()) graph.AddEdge(point(i, j), point(i + 1, j));
            if (j - 1 >= 0) graph.AddEdge(point(i, j), point(i, j - 1));
            if (j+1 < environment.GetSize()) graph.AddEdge(point(i,j),point(i,j+1));
        }
    }

   for (auto v:graph.GetNeighbors(point(0,0))) {
        cout << "VERTEX: ";
        cout << v->name.first << " " << v->name.second << endl;
    }
    return 0;
}