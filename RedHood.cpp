//
// Created by DanMagor on 05.09.2017.
//

#include "RedHood.h"
#include "Environment.h"

RedHood::RedHood(string ID) : Unit(ID) {
    symbol_ = 'R';
    position_ = point(0,0);
    //set wolf detection cells:

}

RedHood::RedHood(pair<int, int> position) : Unit(position) { symbol_ = 'R'; }

void RedHood::SetEnvironment(Environment &environment) {
    environment_ = &environment;
    MakeGraphFromEnvironment();
}

void RedHood::MakeAction() {
    UpdateWolfDetection();
    UpdateBearDetection();
    CheckArea();
    path_ = AStar::FindPath(graph_environment_, position_, goal_);
    if (path_.empty()) Die();
    else {
        SetPosition(path_.top());
        path_.pop();
    }

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

void RedHood::SetGoal(point goal) {
    goal_ = goal;

}

void RedHood::CheckArea() {
    for(auto c:wolf_detection_cells){
        if(environment_->IsWolfDetection(c)){
            graph_environment_.DeleteVertex(c);
        }
    for (auto c:bear_detection_cells){
        if(environment_->IsBearDetection(c)){
            graph_environment_.DeleteVertex(c);
        }
    }
    }

}

void RedHood::UpdateWolfDetection() {
    wolf_detection_cells.clear();
    int y = position_.first; int x = position_.second;
    point temp(y-1,x);
    wolf_detection_cells.push_back(temp);
    temp = point(y-2,x);
    wolf_detection_cells.push_back(temp);
    temp = point(y+1,x);
    wolf_detection_cells.push_back(temp);
    temp = point(y+2,x);
    wolf_detection_cells.push_back(temp);
    temp = point(y,x+1);
    wolf_detection_cells.push_back(temp);
    temp = point(y,x+2);
    wolf_detection_cells.push_back(temp);
    temp = point(y,x-1);
    wolf_detection_cells.push_back(temp);
    temp = point(y,x-2);
    wolf_detection_cells.push_back(temp);
}

void RedHood::UpdateBearDetection(){
    bear_detection_cells.clear();
    int y = position_.first; int x = position_.second;
    point temp(y-1,x);
    bear_detection_cells.push_back(temp);
    temp = point(y+1,x);
    bear_detection_cells.push_back(temp);
    temp = point(y,x+1);
    bear_detection_cells.push_back(temp);
    temp = point(y,x-1);
    bear_detection_cells.push_back(temp);
}

bool RedHood::IsDead() {
    return is_dead_;
}

void RedHood::Die() {
    is_dead_ = true;
}

RedHood::~RedHood() {

}







