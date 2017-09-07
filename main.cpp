#include <iostream>
#include "Environment.h"
#include "RedHood.h"
#include "Granny.h"
#include "Graph.h"


using namespace std;
int main() {

    Environment environment;
    environment.UpdateUnitsPositions();
    environment.PrintCell();

    Granny granny("Granny");
    RedHood redHood("RedHood");
    environment.AddUnit(redHood);
    environment.AddUnit(granny);
    unsigned int a,b;
    cin>>a;
    cin>>b;
    granny.SetPosition(a-1,b-1);
    cin>>a;
    cin>>b;
    redHood.SetPosition(a-1,b-1);
    cout<<endl<<endl<<endl;
    environment.UpdateUnitsPositions();
    environment.PrintCell();
    Graph<Point> graph;
    graph.AddVertex(Point(0,0));
    graph.AddVertex(Point(0,1));
    graph.AddVertex(Point(1,0));
    graph.AddVertex(Point(1,1));
    graph.AddEdge(Point(0,1),Point(0,0));
    graph.AddEdge(Point(1,0),Point(0,1));
    graph.AddEdge(Point(1,0),Point(0,0));
    graph.AddEdge(Point(1,0),Point(1,1));

    for(auto v:graph.GetNeighbors(Point(0,0))){
        cout<<"VERTEX: ";
        cout<<v->name.X()<<" "<<v->name.Y()<<endl;
    }
    return 0;
}