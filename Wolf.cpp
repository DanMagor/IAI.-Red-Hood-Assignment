//
// Created by DanMagor on 08.09.2017.
//

#include "Wolf.h"

Wolf::Wolf(const string &ID) : Unit(ID){
    symbol_ = 'W';
}

void Wolf::SetPosition(point position) {
    position_ = position;
    UpdateDetection();
}

void Wolf::UpdateDetection() {
        detection_cells.clear();
        int y = position_.first; int x = position_.second;
        point temp(y-1,x);
        detection_cells.push_back(temp);
        temp = point(y+1,x);
        detection_cells.push_back(temp);
        temp = point(y,x+1);
        detection_cells.push_back(temp);
        temp = point(y,x-1);
        detection_cells.push_back(temp);
}

Wolf::~Wolf() {

}

void Wolf::SetEnvironment(Environment &environment) {
    environment_ = &environment;
}


bool Wolf::CheckArea() {
    Unit *redhood = environment_->GetUnitWithID("RedHood");
    point pos = redhood->GetPosition();
    if (environment_->IsWolfDetection(pos)){
        redhood->SetLife(0);
        return true;
    }
    return false;
}
void Wolf::MakeAction() {
    CheckArea();
}

void Wolf::SetPosition(int y, int x) {
   position_ = pair<int,int>(y,x);
    UpdateDetection();
}
