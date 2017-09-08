//
// Created by DanMagor on 08.09.2017.
//

#include <set>
#include "SimulationController.h"

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
}

void SimulationController::PlaceUnitsRandomly(Environment &environment) {
    std::srand(time(NULL));
    typedef pair<int, int> point;
    int amount_of_cells = environment.GetSize() * environment.GetSize();
    set<int> cells;  //Cells available for placement
    for (int i = 0; i < amount_of_cells; i++) {
        cells.insert(i);
    }

    //Set Wolf Position
    Unit unit = environment.GetUnitWithID("Wolf");

    int random_cell = rand() % cells.size();
    int y = random_cell / environment.GetSize();
    int x = random_cell % environment.GetSize();
    unit.SetPosition(point(y, x));

    //Set Bear Position
    unit = environment.GetUnitWithID("Bear");
    random_cell = rand() % cells.size();
    y = random_cell / environment.GetSize();
    x = random_cell % environment.GetSize();
    unit.SetPosition(point(y, x));

    //Exclude Bear and Wolf Range
    //Wolf:
    unit = environment.GetUnitWithID("Wolf");
    int pos = unit.GetPosition().first * environment.GetSize() + unit.GetPosition().second;
    cells.erase(pos);
    cells.erase(pos - environment.GetSize());
    cells.erase(pos + environment.GetSize()); // top and down cells
    if (pos % environment.GetSize() != 0) cells.erase(pos - 1);
    if (pos % environment.GetSize() != environment.GetSize() - 1) cells.erase(pos + 1); //left and right

    //Bear:
    unit = environment.GetUnitWithID("Bear");
    pos = unit.GetPosition().first * environment.GetSize() + unit.GetPosition().second;
    cells.erase(pos);
    cells.erase(pos - environment.GetSize());
    cells.erase(pos + environment.GetSize());
    if (pos % environment.GetSize() != 0) {
        cells.erase(pos - 1);
        cells.erase(pos - environment.GetSize() - 1);
    }
    if (pos % environment.GetSize() != environment.GetSize() - 1) {
        cells.erase(pos + 1);
        cells.erase(pos + environment.GetSize() + 1);
    } //left and right

    //Set Granny Position
    unit = environment.GetUnitWithID("Granny");
    random_cell = rand() % cells.size();
    y = random_cell / environment.GetSize();
    x = random_cell % environment.GetSize();
    unit.SetPosition(point(y, x));
    pos = y * environment.GetSize() + x;
    cells.erase(pos);

    //Set Cutter Position
    unit = environment.GetUnitWithID("Cutter");
    random_cell = rand() % cells.size();
    y = random_cell / environment.GetSize();
    x = random_cell % environment.GetSize();
    unit.SetPosition(point(y, x));
    pos = y * environment.GetSize() + x;
    cells.erase(pos);

    //Set RedHood Position
    unit = environment.GetUnitWithID("RedHood");
    random_cell = rand() % cells.size();
    y = random_cell / environment.GetSize();
    x = random_cell % environment.GetSize();
    unit.SetPosition(point(y, x));
    pos = y * environment.GetSize() + x;
    cells.erase(pos);

}
