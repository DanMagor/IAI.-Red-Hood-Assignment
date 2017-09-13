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
         << "If you don't want to look on demonstrations write '0'." << endl
         << "Attention with delay you will not see clear real time statistics" << endl;
    int delay;
    cin >> delay;
    int astar_success, backtrack_success = 0;
    cout << "WAIT, SIMULATING IS WORKING..." << endl;
    const clock_t begin_time = clock();

    for (int i = 0; i < n; i++) {
        std::srand(i);
        if (SimulationController::StartAStarSimulation(DEFAULT_SIZE, delay))
            ++astar_success;
    }
    float astar_time = float(clock() - begin_time) / CLOCKS_PER_SEC / n;

    const clock_t begin_time1 = clock();
    for (int i = 0; i < n; i++) {
        std::srand(i);
        if (SimulationController::StartBacktrackingSimulation(DEFAULT_SIZE, delay))
            ++backtrack_success;
    }
    float backtrack_time = float(clock() - begin_time1) / CLOCKS_PER_SEC / n;
    system("CLS");
    cout << "Average amount of time for A* algorithm: " << astar_time << " sec" << endl;
    cout << "Wins: " << astar_success << "  Lose: " << n - astar_success << endl;
    cout << "Average amount of time for BackTracking algorithm: " << backtrack_time << " sec" << endl;
    cout << "Wins: " << backtrack_success << "  Lose: " << n - backtrack_success << endl;
    system("PAUSE");

    return 0;
}