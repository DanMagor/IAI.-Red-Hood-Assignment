//
// Created by DanMagor on 08.09.2017.
//

#ifndef ASSIGNMENT1_WOLF_H
#define ASSIGNMENT1_WOLF_H


#include "Unit.h"
typedef pair<int,int> point;
class Wolf : public Unit{
private:
    vector<point>detection_cells;
    void UpdateDetection();
public:
    Wolf(const string &);
    ~Wolf();

    void SetPosition(point position);
};


#endif //ASSIGNMENT1_WOLF_H
