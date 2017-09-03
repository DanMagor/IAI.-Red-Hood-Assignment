//
// Created by DanMagor on 03.09.2017.
//
/*
 * Representation of square lattice(for default has 9x9 size).
 * Environment contains information about all objects in our task.
 * It is represented by 2-dimensional array where array[i][j] is
 * a point lying on the i-th row and j-th column.
 */

#ifndef ASSIGNMENT1_ENVIRONMENT_H
#define ASSIGNMENT1_ENVIRONMENT_H
#define DEFAULT_SIZE 9

#include "Unit.h"
#include <vector>
#include <array>

using namespace std;

class Environment {
private:
    int size_;       //width and length of lattice
    Unit ***lattice; //two dimensional dynamic array with pointers on Unit
public:

    Environment();

    Environment(int);  // constructor for non default lattice
    ~Environment();

    // Environment Information
    int GetSize();     //return environment size (width and length)
    void PrintCell();

    //Unit interaction
    bool IsEmptyCell(Point);

    Unit GetUnitFromCell(Point);

    void CheckOverlap();

    void PlaceUnitAtCell(Unit &unit,Point);  //#TODO Write Exception

};


#endif //ASSIGNMENT1_ENVIRONMENT_H
