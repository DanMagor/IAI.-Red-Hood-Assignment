//
// Created by DanMagor on 15.09.2017.
//

#include "Cutter.h"
#include <algorithm>
Cutter::Cutter(const string &ID) : Unit(ID){
    symbol_ = 'C';
}

void Cutter::MakeAction() {
    if (CheckArea()){
        Unit *r = environment_->GetUnitWithID("RedHood");
        r->SetLife(6);
    }
}

bool Cutter::CheckArea() {
    point c = environment_->GetUnitWithID("RedHood")->GetPosition();
    vector<point> detection = DetectionCells();
    auto result = find(detection.begin(),detection.end(),c);
    return result != detection.end();
}

vector<point> Cutter::DetectionCells() {
    vector<point> cells;
    cells.emplace_back(position_);
    return cells;

}
