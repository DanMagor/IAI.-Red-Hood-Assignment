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
#include <string.h>
#include <map>

using namespace std;

class Environment {
private:
    int size_;       //width and length of lattice
    Unit ***lattice; //two dimensional dynamic array with pointers on Unit
    map<string, Unit*> units_;
public:
    typedef pair<int,int> point;
    //Initialization
    Environment();
    explicit Environment(int);  // constructor for non default lattice


    // Environment Information
    int GetSize();     //return environment size (width and length)
    void PrintCell();
    Unit* GetUnitWithID(string);   //return a reference of unit in environment with specific ID
    bool IsWolfDetection(point);
    bool IsBearDetection(point);

    //Unit interaction
    void AddUnit(Unit&);   //add Unit in environment
    void UpdateUnitsPositions();  //Check positions of Units and update it for lattice


    //Destructor
    ~Environment();



};


#endif //ASSIGNMENT1_ENVIRONMENT_H
