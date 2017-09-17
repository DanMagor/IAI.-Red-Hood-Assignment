//
// Created by DanMagor on 15.09.2017.
//

#ifndef ASSIGNMENT_1_V2_UNIT_H
#define ASSIGNMENT_1_V2_UNIT_H

#include <vector>
#include <string>
#include "../Environement/Environment.h"

using namespace std;

typedef pair<int, int> point;
class Environment;
class Unit {

protected:
    string ID_;   // for access in environment;
    point position_; //
    char symbol_ = ' '; //for visualization
    int life_ = 6;
    bool is_life = true;
    Environment *environment_;
    virtual bool CheckArea() = 0;

public:
    //Initialization
     explicit Unit(string);

     Unit(string, point);

     Unit(string, int, int);

    virtual void SetEnvironment(Environment&);

    //Units information
    string GetID();

    char GetSymbol();

    point GetPosition();

    int GetLife();

    bool IsLife();

    //Behavior
    virtual void SetPosition(point);

    virtual void SetPosition(int, int);

    virtual void MakeAction() = 0;

    //State control:
    void SetLife(int);

    virtual void Die();


};


#endif //ASSIGNMENT_1_V2_UNIT_H
