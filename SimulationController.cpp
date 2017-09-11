//
// Created by DanMagor on 08.09.2017.
//

#include <set>
#include "SimulationController.h"
#include <windows.h>
#include <iostream> //TODO: DELETE
using namespace std;
void SimulationController::StartSimulation(int environment_size = DEFAULT_SIZE) {
    //Create and initialize environment
    Environment environment(environment_size);

    //Create Units for Environment
    RedHood redHood("RedHood");
    Granny granny("Granny");
    Wolf wolf("Wolf");
    Bear bear("Bear");
    Cutter cutter("Cutter");

    //Add Units in Environment
    environment.AddUnit(redHood);
    environment.AddUnit(granny);
    environment.AddUnit(wolf);
    environment.AddUnit(bear);
    environment.AddUnit(cutter);

    // Place Unit
    PlaceUnitsRandomly(environment);
    environment.UpdateUnitsPositions();
    environment.PrintCell();
    //TEST



    environment.UpdateUnitsPositions();
    redHood.SetGoal(granny.GetPosition());
    int delay = 200;
    redHood.SetEnvironment(environment);

    while(redHood.GetPosition()!=granny.GetPosition() && !redHood.IsDead()){
        system("CLS");
        redHood.MakeAction();
        environment.UpdateUnitsPositions();
        environment.PrintCell();
        cout<<endl;
        Sleep(delay);
    }
    if (redHood.IsDead()) {cout<<endl<<"DIIIIIE";
    Sleep(2000);}



}

void SimulationController::PlaceUnitsRandomly(Environment &environment) {
    std::srand(time(NULL));
    typedef pair<int, int> point;
    int size = environment.GetSize();
    int amount_of_cells = environment.GetSize() * environment.GetSize();
    map<int,point> cells;  //Cells available for placement
    for (int i = 0; i < amount_of_cells; i++) {
        int y = i / size; int x = i%size;
        cells[i] = point(y,x);
    }

    //Set RedHood Position
    Unit* unit = environment.GetUnitWithID("RedHood");
    int random_index = 0;
    auto iter = cells.begin();
    advance(iter, random_index);
    int key = iter->first;
    point p = iter->second;
    unit->SetPosition(p);
    cells.erase(key);
    //Also need to array neighbors cells
    cells.erase(key+1); cells.erase(key+size); cells.erase(key+size+1);

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
