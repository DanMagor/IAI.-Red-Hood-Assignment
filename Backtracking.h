//
// Created by DanMagor on 12.09.2017.
//

#ifndef ASSIGNMENT1_BACKTRACKING_H
#define ASSIGNMENT1_BACKTRACKING_H

#include <stack>
#include "Graph.h"
#include "Environment.h"
#include <vector>
#include <algorithm>
typedef pair<int,int> point;
class Backtracking {
private:
    static bool Solve(Graph<point>&,Environment*,point);
public:
    static stack<point> FindPath(Graph<point>&,Environment*,point,point);

};


#endif //ASSIGNMENT1_BACKTRACKING_H
