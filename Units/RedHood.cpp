//
// Created by DanMagor on 15.09.2017.
//

#include <algorithm>
#include "RedHood.h"
#include "../Algorithms/AStar.h"
#include "../Algorithms/Backtracking.h"


RedHood::RedHood(string ID) : Unit(ID) {
    symbol_ = 'R';


}

RedHood::RedHood(string ID, point position) : Unit(ID, position) {
    symbol_ = 'R';
}

RedHood::RedHood(string ID, int y, int x) : Unit(ID, y, x) {
    symbol_ = 'R';
}

void RedHood::MakeGraphFromEnvironment() {
    Graph<point> graph;
    for (int i = 0; i < environment_->GetSize(); i++) {
        for (int j = 0; j < environment_->GetSize(); j++) {
            graph.AddVertex(point(i, j));
        }
    }
    for (int i = 0; i < environment_->GetSize(); i++) {
        for (int j = 0; j < environment_->GetSize(); j++) {
            if (i - 1 >= 0) graph.AddEdge(point(i, j), point(i - 1, j));
            if (i + 1 < environment_->GetSize()) graph.AddEdge(point(i, j), point(i + 1, j));
            if (j - 1 >= 0) graph.AddEdge(point(i, j), point(i, j - 1));
            if (j + 1 < environment_->GetSize()) graph.AddEdge(point(i, j), point(i, j + 1));
        }
    }
    graph_environment_ = graph;
}

void RedHood::MakeAction() {
    if (path_.empty()) path_ = AStar::FindPath(graph_environment_, position_, goal_);
    if (CheckArea()) {
        path_ = AStar::FindPath(graph_environment_, position_, goal_);
    }
    if (path_.empty() || life_ <= 0) Die();
    else {
        SetPosition(path_.top());
        path_.pop();
    }
}

void RedHood::SetGoal(point goal) {
    goal_ = goal;
}

bool RedHood::CheckArea() {
    bool danger_detected = false;
    vector<point> detection = WolfDetectionCells();
    for (auto c: environment_->WolfDetectionCells()) {
        if (find(detection.begin(), detection.end(), c) != detection.end()) {
            graph_environment_.DeleteVertex(c);
            danger_detected = true;
        }
    }
    detection = BearDetectionCells();
    for (auto c:environment_->BearDetectionCells()){
        if (find(detection.begin(), detection.end(), c) != detection.end()) {
            for(auto v: graph_environment_.GetNeighbors(c)){
                graph_environment_.SetEdgeWeight(v,c,100);
            }
            danger_detected = true;
        }
    }
    return danger_detected;
}

void RedHood::SetEnvironment(Environment &environment) {
    Unit::SetEnvironment(environment);
    MakeGraphFromEnvironment();
}

vector<point> RedHood::WolfDetectionCells() {
    vector<point> cells;
    int y = GetPosition().first, x = GetPosition().second;
    cells.emplace_back(y, x);
    cells.emplace_back(y + 1, x);
    cells.emplace_back(y - 1, x);
    cells.emplace_back(y, x + 1);
    cells.emplace_back(y, x - 1);
    cells.emplace_back(y + 2, x);
    cells.emplace_back(y - 2, x);
    cells.emplace_back(y, x + 2);
    cells.emplace_back(y, x - 2);
    return cells;
}

vector<point> RedHood::BearDetectionCells() {
    vector<point> cells;
    int y = GetPosition().first, x = GetPosition().second;
    cells.emplace_back(y, x);
    cells.emplace_back(y + 1, x);
    cells.emplace_back(y - 1, x);
    cells.emplace_back(y, x + 1);
    cells.emplace_back(y, x - 1);
    return cells;
}

void RedHood::MakeActionBacktracking() {
    if (path_.empty()) {
        CheckArea();
        path_ = Backtracking::FindPath(graph_environment_, environment_, position_, goal_);
    }
    CheckArea();
    if (path_.empty() || life_ <= 0) Die();
    else {
        SetPosition(path_.top());
        path_.pop();
        CheckArea();
    }
}
