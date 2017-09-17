//
// Created by DanMagor on 15.09.2017.
//

#include <iostream>
#include <algorithm>
#include "Environment.h"
#include "../Units/Wolf.h"

Environment::Environment()  {

    lattice_ = new Unit **[size_];

    for (int i = 0; i < size_; ++i)
        lattice_[i] = new Unit *[size_];


    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            lattice_[i][j] = nullptr;


}

Environment::Environment(int size): size_(size){
    lattice_ = new Unit **[size_];

    for (int i = 0; i < size_; ++i)
        lattice_[i] = new Unit *[size_];


    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            lattice_[i][j] = nullptr;

}

Environment::~Environment() {
    if (lattice_!= nullptr) {
        for (int i = 0; i < size_; ++i)
            if (lattice_[i] != nullptr)
                delete lattice_[i];
        if (lattice_ != nullptr)
            delete[] lattice_;
    }
}

void Environment::AddUnit(Unit &unit) {
    if (units_.find(unit.GetID())!= units_.end()) throw std::invalid_argument("Duplicated Unit ID");
    units_[unit.GetID()] = &unit;
}

void Environment::UpdateUnitsPositions() {
    for (int i = 0; i < size_; ++i)
        for (int j = 0; j < size_; ++j)
            lattice_[i][j] = nullptr;
    for (auto u:units_) {
        Unit *unit = u.second;
        int x = unit->GetPosition().second;
        int y = unit->GetPosition().first;
        if (y >=size_ || x >= size_) throw std::out_of_range("Unit placed out of range");
        lattice_[y][x] = unit;
    }
}

int Environment::GetSize() {
    return size_;
}

Unit *Environment::GetUnitWithID(string ID) {
    if (units_.find(ID) == units_.end()) throw std::invalid_argument("No unit with such ID");
    return units_[ID];
}

void Environment::PrintCell() {
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            if (lattice_[i][j] == nullptr) std::cout << "_";
            else cout << lattice_[i][j]->GetSymbol();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

vector<point> Environment::WolfDetectionCells() {
    vector<point> cells;
    Unit *wolf = GetUnitWithID("Wolf");
    int y = wolf->GetPosition().first, x = wolf->GetPosition().second;
    cells.emplace_back(y,x);
    cells.emplace_back(y+1,x);
    cells.emplace_back(y-1,x);
    cells.emplace_back(y,x+1);
    cells.emplace_back(y,x-1);
    return cells;
}

vector<point> Environment::BearDetectionCells() {
    vector<point> cells;
    Unit *bear = GetUnitWithID("Bear");
    int y = bear->GetPosition().first, x = bear->GetPosition().second;
    cells.emplace_back(y,x);
    cells.emplace_back(y+1,x);
    cells.emplace_back(y-1,x);
    cells.emplace_back(y,x+1);
    cells.emplace_back(y,x-1);
    cells.emplace_back(y+1,x+1);
    cells.emplace_back(y+1,x-1);
    cells.emplace_back(y-1,x+1);
    cells.emplace_back(y-1,x-1);
    return cells;
}

bool Environment::IsWolfDetection(point c) {
    vector<point> cells = WolfDetectionCells();
    return find(cells.begin(),cells.end(),c) != cells.end();
}

bool Environment::IsBearDetection(point c) {
    vector<point> cells = BearDetectionCells();
    return find(cells.begin(),cells.end(),c) != cells.end();
}






