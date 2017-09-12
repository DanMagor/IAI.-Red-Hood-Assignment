//
// Created by DanMagor on 12.09.2017.
//

#ifndef ASSIGNMENT1_BACKTRACKING_H
#define ASSIGNMENT1_BACKTRACKING_H

#include <stack>
#include "Graph.h"
#include <vector>
#include <algorithm>
typedef pair<int,int> point;
class Backtracking {
private:
    static bool Solve(Graph<point>&,point);
public:
    static vector<point> FindPath(Graph<point>&,point,point);

};


#endif //ASSIGNMENT1_BACKTRACKING_H
