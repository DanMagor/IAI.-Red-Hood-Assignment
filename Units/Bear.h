//
// Created by DanMagor on 15.09.2017.
//

#ifndef ASSIGNMENT_1_V2_BEAR_H
#define ASSIGNMENT_1_V2_BEAR_H


#include "Unit.h"

class Bear: public Unit {
private:
    bool CheckArea() override;
    vector<point> DetectionCells();
public:
    explicit Bear(const string &);
    void MakeAction() override;

};


#endif //ASSIGNMENT_1_V2_BEAR_H
