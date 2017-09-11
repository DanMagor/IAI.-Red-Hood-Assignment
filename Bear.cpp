//
// Created by DanMagor on 08.09.2017.
//

#include "Bear.h"
typedef pair<int,int> point;
Bear::Bear(const string &ID) : Unit(ID){
    symbol_ = 'B';
}

void Bear::MakeAction() {
    CheckArea();
}



Bear::~Bear() {

}

void Bear::CheckArea() {
    Unit::CheckArea();
    Unit *redhood = environment_->GetUnitWithID("RedHood");
    point pos = redhood->GetPosition();
    if (environment_->IsBearDetection(pos)){
        redhood->SetLife(redhood->GetLife()-2);
    }
}

void Bear::SetEnvironment(Environment &environment) {
    environment_ = &environment;
}
