//
// Created by DanMagor on 03.09.2017.
//

#include "Unit.h"


Unit::Unit(Point position) : position_(position) {}
Unit::Unit(string id) {
    ID_ = id;
}


void Unit::SetID(string id) {
    ID_ = id;
}

string Unit::GetID() {
    return ID_;
}


void Unit::SetPosition(Point position) {
    position_ = position;
}
void Unit::SetPosition(int y, int x) {
    position_ = Point(x,y);
}

Point Unit::GetPosition() {
    return position_;
}

Unit::~Unit() {}

void Unit::CheckArea() {

}

char Unit::GetSymbol() {
    return symbol_;
}




