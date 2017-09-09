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

Environment::Environment(int size) : size_(size) {
    lattice = new Unit **[size_];

    for (int i = 0; i < size_; ++i)
        lattice[i] = new Unit *[size_];


    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            lattice[i][j] = nullptr;
}

Environment::~Environment() {
    if (lattice!= nullptr) {
        for (int i = 0; i < size_; ++i)
            if (lattice[i] != nullptr)
                delete lattice[i];
        if (lattice != nullptr)
            delete[] lattice;
    }
}


void Environment::AddUnit(Unit &unit) {
    if (units_.find(unit.GetID()) != units_.end()) throw std::invalid_argument("Duplicated Unit ID");
    units_[unit.GetID()] = &unit;
}

void Environment::UpdateUnitsPositions() {
    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            lattice[i][j] = nullptr;
    for (auto u:units_) {
        Unit *unit = u.second;
        int x = unit->GetPosition().second;
        int y = unit->GetPosition().first;
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
            else cout << lattice[i][j]->GetSymbol();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}


int Environment::GetSize() {
    return size_;
}

Unit *Environment::GetUnitWithID(string ID) {
    if (units_.find(ID) == units_.end()) throw std::invalid_argument("No unit with such ID");
    return units_[ID];
}

bool Environment::IsWolfDetection(point p) {
    Unit *wolf = GetUnitWithID("Wolf");
    int y = wolf->GetPosition().first;
    int x = wolf->GetPosition().second;
    point temp(y - 1, x);
    if (p == temp)
        return true;
    temp = point(y + 1, x);
    if (p == temp)
        return true;
    temp = point(y, x + 1);
    if (p == temp)
        return true;
    temp = point(y, x - 1);
    if (p == temp)
        return true;
    temp = point(y, x);
    if (p == temp)
        return true;
    return false;


}

bool Environment::IsBearDetection(point p) {
    Unit *bear = GetUnitWithID("Bear");
    int y = bear->GetPosition().first;
    int x = bear->GetPosition().second;
    point temp(y - 1, x);
    if (p == temp)
        return true;
    temp = point(y + 1, x);
    if (p == temp)
        return true;
    temp = point(y, x + 1);
    if (p == temp)
        return true;
    temp = point(y, x - 1);
    if (p == temp)
        return true;
    temp = point(y + 1, x + 1);
    if (p == temp)
        return true;
    temp = point(y + 1, x - 1);
    if (p == temp)
        return true;
    temp = point(y - 1, x + 1);
    if (p == temp)
        return true;
    temp = point(y - 1, x - 1);
    if (p == temp)
        return true;
    temp = point(y,x);
    if (p==temp)
        return true;
    return false;
}









