//
// Created by DanMagor on 05.09.2017.
//

#include "RedHood.h"
#include "Environment.h"
RedHood::RedHood(string ID) : Unit(ID) {symbol_='R';}
RedHood::RedHood(Point position) : Unit(position){symbol_='R';}

void RedHood::SetEnvironment(const Environment &full_environment, int size) {

    environment_ = new Unit **[size];

    for (int i = 0; i < size; ++i)
        environment_[i] = new Unit *[size];

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            environment_[i][j] = nullptr;

    //RedHood Position
    int y = position_.Y(); int x = position_.X();
    environment_[y][x] = this;

    //Granny Position
    Unit granny = full_environment.GetUnitFromID("Granny");
    y = granny.GetPosition().Y(); x = granny.GetPosition().X();
    environment_[y][x] = &granny;

}




