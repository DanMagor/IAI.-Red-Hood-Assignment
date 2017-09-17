//
// Created by DanMagor on 15.09.2017.
//

#ifndef ASSIGNMENT_1_V2_WOLF_H
#define ASSIGNMENT_1_V2_WOLF_H


#include "Unit.h"

class Wolf: public Unit {
private:
    bool CheckArea() override;
    vector<point> DetectionCells();

public:
    explicit Wolf(const string &);
    void MakeAction() override;

};


#endif //ASSIGNMENT_1_V2_WOLF_H
