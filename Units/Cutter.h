//
// Created by DanMagor on 15.09.2017.
//

#ifndef ASSIGNMENT_1_V2_CUTTER_H
#define ASSIGNMENT_1_V2_CUTTER_H


#include "Unit.h"

class Cutter: public Unit {
public:
    bool CheckArea() override;
    vector<point> DetectionCells();
public:
    void MakeAction() override;
    explicit Cutter(const string &);

};


#endif //ASSIGNMENT_1_V2_CUTTER_H
