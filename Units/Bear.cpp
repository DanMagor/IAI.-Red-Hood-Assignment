//
// Created by DanMagor on 15.09.2017.
//

#include <algorithm>
#include "Bear.h"

Bear::Bear(const string &ID) : Unit(ID){
    symbol_ = 'B';
}

vector<point> Bear::DetectionCells() {
    vector<point> cells;
    int y = GetPosition().first, x = GetPosition().second;
    cells.emplace_back(y,x);
    cells.emplace_back(y+1,x);
    cells.emplace_back(y-1,x);
    cells.emplace_back(y,x+1);
    cells.emplace_back(y,x-1);
    cells.emplace_back(y+1,x+1);
    cells.emplace_back(y+1,x-1);
    cells.emplace_back(y-1,x+1);
    cells.emplace_back(y-1,x-1);
    return cells;
}

void Bear::MakeAction() {
    if (CheckArea()){
        Unit *r = environment_->GetUnitWithID("RedHood");
        r->SetLife(r->GetLife() - 2);
    }
}

bool Bear::CheckArea() {
    point c = environment_->GetUnitWithID("RedHood")->GetPosition();
    vector<point> detection = DetectionCells();
    auto result = find(detection.begin(),detection.end(),c);
    return result != detection.end();
}
