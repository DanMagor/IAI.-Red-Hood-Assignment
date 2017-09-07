//
// Created by DanMagor on 03.09.2017.
//

#include "Environment.h"

//#TODO: DELETE INCLUDE iostream IF NEED NOT
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


void Environment::AddUnit(Unit &unit) {
    if (units_.find(unit.GetID()) != units_.end()) throw std::invalid_argument("Duplicated Unit ID");
    units_[unit.GetID()] = &unit;
}

void Environment::UpdateUnitsPositions() {
    for (auto u:units_) {
        Unit *unit = u.second;
        int x = unit->GetPosition().X();
        int y = unit->GetPosition().Y();
        if (y > size_ - 1 || x > size_ - 1) throw std::out_of_range("Unit placed out of range");
        lattice[y][x] = unit;
    }
}

const Unit &Environment::GetUnitFromCell(const Point &point) {
    int x = point.X();
    int y = point.Y();
    if (y > size_ - 1 || x > size_ - 1)
        throw std::out_of_range("Unit place out of range");
    return *lattice[y][x];

}





//Debug Function #TODO: DELETE IF NEED NOT
void Environment::PrintCell() {

    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (lattice[i][j] == nullptr) std::cout << "_";
            else cout<<lattice[i][j]->GetSymbol();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

const Unit & Environment::GetUnitFromID(string ID)const {
     if (units_.find(ID) == units_.end()) throw std::invalid_argument("No unit with such ID");
    Unit a("DEBUG"); //TODO:DELETE
    return a;
}







