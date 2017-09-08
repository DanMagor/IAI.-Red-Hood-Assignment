//
// Created by DanMagor on 07.09.2017.
//


#include "AStar.h"

typedef pair<int,int> point;
stack<point> AStar::FindPath(const Graph<pair<int,int>> & graph, point start, point goal) {
    queue<point> frontier;
    frontier.push(start);
    map<point,int> cost_so_far;
    map<point,point> came_from;
    came_from[start] = start;
    cost_so_far[start] = 0;
    bool isFindPath = false;
    while(!frontier.empty()){
        point &current = frontier.front();
        if(current == goal) {
            isFindPath = true;
            break;
        }
        for(auto next:graph.GetNeighbors(current)){
            int new_cost = cost_so_far[current] + 1;
            if (cost_so_far.find(next) == cost_so_far.end() || new_cost<cost_so_far[next]){
                cost_so_far[next] = new_cost;
                frontier.push(next);
                came_from[next] = current;
            }
        }
        frontier.pop();
    }
    if (isFindPath)return ConvertMapToStack(came_from,start,goal);
    else{
        stack<point> result;
        return result;
    }

}

stack<point> AStar::ConvertMapToStack(map<point, point> path, point start, point goal) {
    point current = goal;
    stack<point> result;
    result.push(goal);
    while(path[current]!=start){
        result.push(current);
        current = path[current];
    }
    result.push(current);
    return result;
}
