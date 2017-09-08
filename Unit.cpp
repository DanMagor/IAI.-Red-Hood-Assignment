//
// Created by DanMagor on 03.09.2017.
//

#include "Unit.h"


Unit::Unit(pair<int,int> position) : position_(position) {}
Unit::Unit(string id) {
    ID_ = id;
}


void Unit::SetID(string id) {
    ID_ = id;
}

string Unit::GetID() {
    return ID_;
}


void Unit::SetPosition(int y, int x) {
    position_ = pair<int,int>(y,x);
}

pair<int,int> Unit::GetPosition() {
    return position_;
}

Unit::~Unit() {}

void Unit::CheckArea() {

}

char Unit::GetSymbol() {
    return symbol_;
}

void Unit::SetPosition(pair<int,int> position) {
    position_ = position;
}

void Unit::MakeAction() {

}




