//
// Created by DanMagor on 03.09.2017.
//

#include "Unit.h"



Unit::Unit(Point position) : position_(position) {}

void Unit::MoveTo(Point position) {
    position_ = position;
}

Point Unit::GetPosition() {
    return position_;
}

Unit::~Unit() {}

void Unit::CheckArea() {

}
