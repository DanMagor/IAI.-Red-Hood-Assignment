//
// Created by DanMagor on 05.09.2017.
//

#include "RedHood.h"
#include "Environment.h"

RedHood::RedHood(string ID) : Unit(ID) { symbol_ = 'R'; }

RedHood::RedHood(pair<int, int> position) : Unit(position) { symbol_ = 'R'; }

void RedHood::SetEnvironment(Environment &environment) {
    environment_ = environment;
}

void RedHood::MakeAction() {
    MakeGraphFromEnvironment();
    if (path_.empty())
        path_ = AStar::FindPath(graph_environment_, position_, goal_);
    SetPosition(path_.top());
    path_.pop();

}

void RedHood::MakeGraphFromEnvironment() {
    Graph<point> graph;
    for (int i = 0; i < environment_.GetSize(); i++) {
        for (int j = 0; j < environment_.GetSize(); j++) {
            graph.AddVertex(point(i, j));
        }
    }
    for (int i = 0; i < environment_.GetSize(); i++) {
        for (int j = 0; j < environment_.GetSize(); j++) {
            if (i - 1 >= 0) graph.AddEdge(point(i, j), point(i - 1, j));
            if (i + 1 < environment_.GetSize()) graph.AddEdge(point(i, j), point(i + 1, j));
            if (j - 1 >= 0) graph.AddEdge(point(i, j), point(i, j - 1));
            if (j + 1 < environment_.GetSize()) graph.AddEdge(point(i, j), point(i, j + 1));
        }
    }
    graph_environment_ = graph;

}

void RedHood::SetGoal(point goal) {
    goal_ = goal;

}






