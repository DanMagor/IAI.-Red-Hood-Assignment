//
// Created by DanMagor on 15.09.2017.
//

#include <synchapi.h>
#include "SimulationController.h"
#include "../Units/Granny.h"
#include "../Units/Wolf.h"
#include "../Units/Bear.h"
#include "../Units/Cutter.h"

vector<int> SimulationController::StartAStarSimulation(int size, int delay) {
    //Create and initialize environment
    Environment environment(size);
    RedHood redHood("RedHood");
    Granny granny("Granny");
    Wolf wolf("Wolf");
    Bear bear("Bear");
    Cutter cutter("Cutter");

    //Add Units to Environment
    environment.AddUnit(redHood);
    environment.AddUnit(granny);
    environment.AddUnit(wolf);
    environment.AddUnit(bear);
    environment.AddUnit(cutter);

    //Place Unit
    PlaceUnitsRandomly(environment);

    environment.UpdateUnitsPositions();
    //Units Initialization
    redHood.SetGoal(granny.GetPosition());
    redHood.SetEnvironment(environment);
    wolf.SetEnvironment(environment);
    bear.SetEnvironment(environment);


    vector<int> statistic;
    int steps = 0;
    //Simulation:
    while (redHood.GetPosition() != granny.GetPosition() && redHood.IsLife()) {
        if (delay != 0) {
            environment.PrintCell();
            Sleep(delay);
            system("CLS");
        }
        redHood.MakeAction();
        wolf.MakeAction();
        bear.MakeAction();
        environment.UpdateUnitsPositions();
        ++steps;

    }
    statistic.push_back(redHood.IsLife());
    statistic.push_back(steps);
    return statistic;

}



void SimulationController::PlaceUnitsRandomly(Environment &environment) {
    typedef pair<int, int> point;
    int size = environment.GetSize();
    int amount_of_cells = environment.GetSize() * environment.GetSize();
    map<int, point> cells;  //Cells available for placement
    for (int i = 0; i < amount_of_cells; i++) {
        int y = i / size;
        int x = i % size;
        cells[i] = point(y, x);
    }

    //Set RedHood Position
    Unit *unit = environment.GetUnitWithID("RedHood");
    int random_index = 0;
    auto iter = cells.begin();
    advance(iter, random_index);
    int key = iter->first;
    point p = iter->second;
    unit->SetPosition(p);
    cells.erase(key);
    //Also need to array neighbors cells
    cells.erase(key + 1);
    cells.erase(key + size);
    cells.erase(key + size + 1);

    //Set Wolf Position
    unit = environment.GetUnitWithID("Wolf");
    random_index = rand() % cells.size();
    iter = cells.begin();
    advance(iter, random_index);
    key = iter->first;
    p = iter->second;
    unit->SetPosition(p);
    cells.erase(key);

    //Set Bear Position
    unit = environment.GetUnitWithID("Bear");
    random_index = rand() % cells.size();
    iter = cells.begin();
    advance(iter, random_index);
    key = iter->first;
    p = iter->second;
    unit->SetPosition(p);
    cells.erase(key);


    // Delete bear and wolf range from available cells
    //Bear:
    cells.erase(key - size);
    cells.erase(key + size);
    if (key % size != 0) {
        cells.erase(key - 1);
        cells.erase(key - size - 1);
        cells.erase(key + size - 1);
    }
    if (key % environment.GetSize() != size - 1) {
        cells.erase(key + 1);
        cells.erase(key + size + 1);
        cells.erase(key - size + 1);
    }
    //Wolf:
    unit = environment.GetUnitWithID("Wolf");
    key = unit->GetPosition().first * size + unit->GetPosition().second;
    cells.erase(key - size);
    cells.erase(key + size); // top and down cells
    if (key % size != 0) cells.erase(key - 1);
    if (key % size != size - 1) cells.erase(key + 1); //left and right



    //Set Granny Position
    unit = environment.GetUnitWithID("Granny");
    random_index = rand() % cells.size();
    iter = cells.begin();
    advance(iter, random_index);
    key = iter->first;
    p = iter->second;
    unit->SetPosition(p);
    cells.erase(key);

    //Set Cutter Position
    unit = environment.GetUnitWithID("Cutter");
    random_index = rand() % cells.size();
    iter = cells.begin();
    advance(iter, random_index);
    key = iter->first;
    p = iter->second;
    unit->SetPosition(p);
    cells.erase(key);
}

vector<int> SimulationController::StartBacktrackingSimulation(int size, int delay) {
    Environment environment(size);
    RedHood redHood("RedHood");
    Granny granny("Granny");
    Wolf wolf("Wolf");
    Bear bear("Bear");
    Cutter cutter("Cutter");

    //Add Units to Environment
    environment.AddUnit(redHood);
    environment.AddUnit(granny);
    environment.AddUnit(wolf);
    environment.AddUnit(bear);
    environment.AddUnit(cutter);

    //Place Unit
    PlaceUnitsRandomly(environment);

    environment.UpdateUnitsPositions();
    //Units Initialization
    redHood.SetGoal(granny.GetPosition());
    redHood.SetEnvironment(environment);
    wolf.SetEnvironment(environment);
    bear.SetEnvironment(environment);

    vector<int> statistic;
    int steps = 0;
    //Simulation:
    while (redHood.GetPosition() != granny.GetPosition() && redHood.IsLife()) {
        if (delay != 0) {
            environment.PrintCell();
            Sleep(delay);
            system("CLS");
        }
        redHood.MakeActionBacktracking();
         wolf.MakeAction();
        bear.MakeAction();
        environment.UpdateUnitsPositions();
        ++steps;

    }
    statistic.push_back(redHood.IsLife());
    statistic.push_back(steps);
    return statistic;
}
