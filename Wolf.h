//
// Created by DanMagor on 08.09.2017.
//

#ifndef ASSIGNMENT1_WOLF_H
#define ASSIGNMENT1_WOLF_H


#include "Unit.h"
#include "Environment.h"

typedef pair<int,int> point;
class Wolf : public Unit{
private:
    vector<point>detection_cells;
    void UpdateDetection();
    Environment *environment_;
public:
    Wolf(const string &);
    ~Wolf();
    void SetEnvironment(Environment &);
    void SetPosition(point position);

    void CheckArea();

    void MakeAction();
};


#endif //ASSIGNMENT1_WOLF_H
