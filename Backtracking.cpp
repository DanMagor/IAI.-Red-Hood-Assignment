//
// Created by DanMagor on 12.09.2017.
//

#include <queue>
#include "Backtracking.h"

int i = 0;

queue<point> Backtracking::FindPath(Graph<point> &graph, point start, point goal) {
    map<int, point> path;
    queue<point> q;
    if (!Solve(graph, start, goal, path)) {
        while (!path.empty()) {
            i = 0;
            if (path.find(i) != path.end()) {
                q.push(path[i]);
                path.erase(i);
            }
            i++;
        }
    }
    return q;

}

bool Backtracking::Solve(Graph<point> &graph, point start, point goal, map<int, point> &path) {
    if (start == goal) {
        path[i] = start;
        return true;
    }
    if (graph.ContainsVertex(start)) {
        if (path.find(i) != path.end())
            return false;
        path[i] = start;
        point temp = point(start.first - 1, start.second);
        if (Solve(graph, temp, goal, path)) return true;

        temp = point(start.first, start.second - 1);
        if (Solve(graph, temp, goal, path)) return true;

        temp = point(start.first + 1, start.second);
        if (Solve(graph, temp, goal, path)) return true;

        temp = point(start.first, start.second + 1);
        if (Solve(graph, temp, goal, path)) return true;

        path.erase(i);
        return false;
    }

}

