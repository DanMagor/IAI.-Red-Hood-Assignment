//
// Created by DanMagor on 03.09.2017.
//

#ifndef ASSIGNMENT1_UNIT_H
#define ASSIGNMENT1_UNIT_H

#include <vector>
#include "Point.h"

using namespace std;

class Unit {
protected:
    Point position_; //the position of unit in environment
public:
    //Initialization
    Unit(Point); //constructor with default position on the field;

    //Unit information
    Point GetPosition();

    //Unit Behavior
    virtual void MoveTo(Point);

    virtual void CheckArea();

    //Destructor
    ~Unit();
};


#endif //ASSIGNMENT1_UNIT_H
