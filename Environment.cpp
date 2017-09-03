//
// Created by DanMagor on 03.09.2017.
//

#include "Environment.h"

//#TODO: DELETE INCLUDE:
#include <iostream>

//Default Constructor. Lattice has size 9x9
Environment::Environment() : size_(DEFAULT_SIZE) {

    lattice = new Unit **[size_];

    for (int i = 0; i < size_; ++i)
        lattice[i] = new Unit *[size_];


    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            lattice[i][j] = nullptr;


}

Environment::~Environment() {
    for (int i = 0; i < size_; ++i)
        delete[] lattice[i];
    delete[] lattice;
}


void Environment::PlaceUnitAtCell(Unit &unit, Point  position) {
    int x = position.X(), y = position.Y();
    if (x > size_ || y > size_) throw std::out_of_range("Place Unit out of range");
    if (lattice[x][y] == nullptr) lattice[x][y] = &unit;
    else CheckOverlap();
    unit.MoveTo(position);
}

//Debug Function
void Environment::PrintCell() {

    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (lattice[i][j] == nullptr) std::cout << "_";
            else std::cout << "*";
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Environment::CheckOverlap() {
}


