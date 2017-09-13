//
// Created by DanMagor on 05.09.2017.
//

#ifndef ASSIGNMENT1_REDHOOD_H
#define ASSIGNMENT1_REDHOOD_H
#include "Unit.h"
#include <stack>
#include <queue>
#include "Environment.h"
#include "AStar.h"
#include "Backtracking.h"
#include "Graph.h"
typedef pair<int,int> point;
class RedHood: public Unit {
private:
    //Properties:
    Environment *environment_;
    Graph<point> graph_environment_;
    point goal_;
    bool is_dead_ = false;
    stack<point> path_;
    stack<point> path_backtracking_;
    vector<point> wolf_detection_cells;
    vector<point> bear_detection_cells;
    int life_;
    //Local methods:
    void MakeGraphFromEnvironment();
    bool CheckArea() override;
    void UpdateWolfDetection();
    void UpdateBearDetection();
public:
    //Initialization
    RedHood(string);
    RedHood(point);
    ~RedHood();
    void SetGoal(point);
    void SetCutterPositions(point,point);
    void SetEnvironment(Environment &);  //Set available environment information for RedHood
    void MakeAction();
    void MakeActionBacktracking();
    int GetLife() override;
    void SetLife(int);

    void Die();
    bool IsDead();

    bool CheckAreaBacktracking();
};


#endif //ASSIGNMENT1_REDHOOD_H
