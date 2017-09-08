//
// Created by DanMagor on 05.09.2017.
//

#ifndef ASSIGNMENT1_REDHOOD_H
#define ASSIGNMENT1_REDHOOD_H
#include "Unit.h"
#include <list>
#include "Environment.h"

class RedHood: public Unit {
private:
    Unit ***environment_;
    Point goal;
public:
    //Initialization
    RedHood(string);
    RedHood(pair<int,int>);
    void SetCutterPositions(pair<int,int>,pair<int,int>);
    void SetEnvironment(const Environment &,int);  //Set available environment information for RedHood

    //Environment information
    void FindPath();


};


#endif //ASSIGNMENT1_REDHOOD_H
