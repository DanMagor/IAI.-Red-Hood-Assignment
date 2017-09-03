//
// Created by DanMagor on 03.09.2017.
//

#include "Point.h"


Point::Point(unsigned int x, unsigned int y) {
    x_ = x;
    y_ = y;
}


void Point::setX(unsigned int x) {
    x_ = x;
}

void Point::setY(unsigned int y) {
    y_ = y;
}

unsigned int Point::X() {
    return x_;
}

unsigned int Point::Y() {
    return y_;
}

