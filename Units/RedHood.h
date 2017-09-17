//
// Created by DanMagor on 15.09.2017.
//

#ifndef ASSIGNMENT_1_V2_REDHOOD_H
#define ASSIGNMENT_1_V2_REDHOOD_H


#include <stack>
#include "Unit.h"
#include "../Environement/Environment.h"
#include "../Environement/Graph.h"

class RedHood: public Unit {
private:
    //Properties:
    Graph<point> graph_environment_;
    point goal_;
    stack<point> path_;
    vector<point> WolfDetectionCells();
    vector<point> BearDetectionCells();
    void MakeGraphFromEnvironment();
    bool CheckArea() override;

public:
    //Initialization
    explicit RedHood(string);
    RedHood(string,point);
    RedHood(string,int,int);
    //Behaviour
    void MakeAction() override;
    void MakeActionBacktracking();
    void SetEnvironment(Environment &) override;
    void SetGoal(point);


};


#endif //ASSIGNMENT_1_V2_REDHOOD_H
