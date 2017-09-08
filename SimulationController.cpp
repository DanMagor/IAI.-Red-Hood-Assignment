//
// Created by DanMagor on 08.09.2017.
//

#include <c++/4.8.3/set>
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
}

void SimulationController::PlaceUnitsRandomly(Environment &environment) {
    std::srand(time(NULL));
    typedef pair<int, int> point;
    int amount_of_cells = environment.GetSize()*environment.GetSize();
    set<int> cells;
    for (int i=0; i<amount_of_cells;i++){
        cells.insert(i);
    }
    //Set Wolf Position
    Unit temp = environment.GetUnitWithID("Wolf");
    int random_cell = rand()%amount_of_cells; amount_of_cells--;
    int y = random_cell/environment.GetSize();
    int x = random_cell % environment.GetSize();
    temp.SetPosition(point(y, x));

    cells.erase(random_cell);
    //Set Bear Position
    temp = environment.GetUnitWithID("Bear");
    y = rand() % environment.GetSize();
    x = rand() % environment.GetSize();
    temp.SetPosition(point(y,x));
    //Set Granny Position

}
