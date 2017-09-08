//
// Created by DanMagor on 07.09.2017.
//

#ifndef ASSIGNMENT1_ASTAR_H
#define ASSIGNMENT1_ASTAR_H


#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <queue>
#include "Graph.h"

using namespace std;
typedef pair<int,int> point;
class AStar {
public:
    static map<point,point> FindPath(const Graph<pair<int,int>>&,pair<int,int>, pair<int,int>);
};


#endif //ASSIGNMENT1_ASTAR_H
