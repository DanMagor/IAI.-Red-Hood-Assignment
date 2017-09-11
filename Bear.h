//
// Created by DanMagor on 08.09.2017.
//

#ifndef ASSIGNMENT1_BEAR_H
#define ASSIGNMENT1_BEAR_H


#include "Unit.h"
#include "Environment.h"

class Bear : public Unit {
private:
Environment *environment_;
public:
    Bear(const string &);
    ~Bear();


    void MakeAction();
    void CheckArea();
    void SetEnvironment(Environment &);

};


#endif //ASSIGNMENT1_BEAR_H
