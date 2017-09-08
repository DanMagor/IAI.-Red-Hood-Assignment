//
// Created by DanMagor on 08.09.2017.
// The purpose of that class is to simulate different tests for environment
// Also, it controls the end condition of simulation.

#ifndef ASSIGNMENT1_SIMULATIONCONTROLLER_H
#define ASSIGNMENT1_SIMULATIONCONTROLLER_H

//Environment:
#include "Environment.h"
#include "Graph.h"
#include <time.h>


//Units:
#include "Unit.h"
#include "RedHood.h"
#include "Granny.h"
#include "Wolf.h"
#include "Bear.h"
#include "Cutter.h"

class SimulationController {
public:
    static void StartSimulation(int);

private:
    static void PlaceUnitsRandomly(Environment&);
};


#endif //ASSIGNMENT1_SIMULATIONCONTROLLER_H
