//
// Created by DanMagor on 05.09.2017.
//

#ifndef ASSIGNMENT1_REDHOOD_H
#define ASSIGNMENT1_REDHOOD_H
#include "Unit.h"
#include <stack>
#include "Environment.h"
#include "AStar.h"
#include "Graph.h"
typedef pair<int,int> point;
class RedHood: public Unit {
private:
    //Properties:
    Environment environment_;
    Graph<point> graph_environment_;
    point goal_;
    stack<point> path_;
    //Local methods:
    void MakeGraphFromEnvironment();
public:
    //Initialization
    RedHood(string);
    RedHood(point);
    void SetGoal(point);
    void SetCutterPositions(point,point);
    void SetEnvironment(Environment &);  //Set available environment information for RedHood




    void MakeAction();
};


#endif //ASSIGNMENT1_REDHOOD_H
