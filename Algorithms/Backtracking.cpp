//
// Created by DanMagor on 16.09.2017.
//

#include "Backtracking.h"
point goal_;
map<point, int> marked;
stack<point> path;

stack<point> Backtracking::FindPath(Graph<point> &graph, Environment *environment, point start, point goal) {
    goal_ = goal;
    marked = map<point,int>();
    path = stack<point>();

    if(Solve(graph,environment,start)) {
        stack<point> result;
        result.push(goal);
        while(!path.empty()) {

            point &temp = path.top();
            result.push(temp);
            path.pop();
        }
        return result;
    }
    return stack<point>();

}

bool Backtracking::Solve(Graph<point> &graph, Environment *environment, point from) {
    marked[from] = 1;
    for(auto v:graph.GetNeighbors(from)){
        if (marked[v] != 0) continue;
        path.push(v);
        if (goal_==v)
            return true;
        marked[v] = 1;
        if (environment->IsWolfDetection(v) || environment->IsBearDetection(v)){
            path.pop();
        }else
        if (Solve(graph,environment,v)) return true;
    }
    return false;
}
