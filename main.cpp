#include <iostream>
#include "Environment.h"
#include "RedHood.h"
#include "Granny.h"
#include "Graph.h"
#include "AStar.h"
#include <stack>

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

    Graph<pair<int, int>> graph;
    typedef pair<int, int> point;

    for (int i = 0; i < environment.GetSize(); i++) {
        for (int j = 0; j < environment.GetSize(); j++) {
            graph.AddVertex(point(i, j));
        }
    }


    for (int i = 0; i < environment.GetSize(); i++) {
        for (int j = 0; j < environment.GetSize(); j++) {
            if (i - 1 >= 0) graph.AddEdge(point(i, j), point(i - 1, j));
            if (i + 1 < environment.GetSize()) graph.AddEdge(point(i, j), point(i + 1, j));
            if (j - 1 >= 0) graph.AddEdge(point(i, j), point(i, j - 1));
            if (j + 1 < environment.GetSize()) graph.AddEdge(point(i, j), point(i, j + 1));
        }
    }
    map<point,point> reverse_path = AStar::FindPath(graph,point(0,0),point(3,0));
    point current(3,0);
    stack<point> path;
    path.push(current);
    while(reverse_path[current]!=point(0,0)){
        path.push(reverse_path[current]);
        current = reverse_path[current];
    }
    path.push(point(0,0));
    while (!path.empty()){
        cout<<path.top().first<<" "<<path.top().second<<"  ";
        path.pop();
    }





    return 0;
}