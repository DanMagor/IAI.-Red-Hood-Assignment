//
// Created by DanMagor on 12.09.2017.
//


#include <algorithm>
#include "Backtracking.h"


point goal_;
map<point, int> marked;
map<point, point> come_from;

vector<point> Backtracking::FindPath(Graph<point> &graph, point start, point goal) {
    goal_ = goal;

    if(Solve(graph,start)) {
        vector<point> result;
        for(auto v: marked){

            if (v.second == 1)
                result.push_back(v.first);
        }
        result.erase(result.begin());
        return result;
    }
    return vector<point>();



}

bool Backtracking::Solve(Graph<point> &graph, point from) {

    if(from == goal_){
        marked[from] = 1;
        return true;
    }

    if (from.first<9 && from.second<9){
        marked[from] = 1;
        point temp = point(from.first,from.second+1);
        if (Solve(graph,temp)) return true;
        temp = point(from.first+1,from.second);
        if (Solve(graph,temp)) return true;
        marked[from] = 0;
        return false;
    }

    return false;


}

