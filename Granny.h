//
// Created by DanMagor on 05.09.2017.
//

#ifndef ASSIGNMENT1_GRANNY_H
#define ASSIGNMENT1_GRANNY_H


#include "Unit.h"
typedef pair<int,int> point;
class Granny: public Unit {
public:
    Granny(string);
    Granny(pair<int,int>);
    ~Granny();

};


#endif //ASSIGNMENT1_GRANNY_H
