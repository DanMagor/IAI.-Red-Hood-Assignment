#include <iostream>
#include "Environment.h"
#include "SimulationController.h"

#define DEFAULT_SIZE 9
using namespace std;

int main() {


    for(int i = 0; i<100; i++) {
        SimulationController::StartSimulation(DEFAULT_SIZE);
    }




    return 0;
}