//
// Created by DanMagor on 15.09.2017.
//

#ifndef ASSIGNMENT_1_V2_SIMULATIONCONTROLLER_H
#define ASSIGNMENT_1_V2_SIMULATIONCONTROLLER_H

//Environment:
#include "Environment.h"
#include <time.h>


//Units:


class SimulationController {
public:
    static vector<int> StartAStarSimulation(int,int);
    static vector<int> StartBacktrackingSimulation(int,int);

private:
    static void PlaceUnitsRandomly(Environment&);
};


#endif //ASSIGNMENT_1_V2_SIMULATIONCONTROLLER_H
