#include <iostream>
#include <synchapi.h>
#include "Environment.h"
#include "SimulationController.h"

#define DEFAULT_SIZE 9
using namespace std;

int main() {

    cout << "Enter the desired number of tests: ";
    int n;
    cin >> n;
    cout << "Enter the time of delay for step(in micro sec) during demonstration." << endl
         << "If you don't want to look on demonstrations write '0':" << endl;
    int delay;
    cin>>delay;

    clock_t begin_time = clock();
    for (int i = 0; i < n; i++) {
        SimulationController::StartAStarSimulation(DEFAULT_SIZE, delay);
    }
    float astar_time = float(clock() - begin_time)/CLOCKS_PER_SEC/n;
    begin_time = clock();

    for (int i = 0; i < n; i++) {
        SimulationController::StartBacktrackingSimulation(DEFAULT_SIZE, delay);
    }
    float backtrack_time = float(clock() - begin_time)/CLOCKS_PER_SEC/n;
    cout<<"Average amount of time for A* algorithm: "<<astar_time<<"micro sec"<<endl;
    cout<<"Average amount of time for BackTracking algorithm: "<<backtrack_time<<"micro sec"<<endl;
    system("PAUSE");

    return 0;
}