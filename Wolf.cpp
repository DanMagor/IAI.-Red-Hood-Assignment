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
