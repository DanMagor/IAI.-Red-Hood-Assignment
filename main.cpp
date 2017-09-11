#include <iostream>
#include "Environment.h"
#include "SimulationController.h"

#define DEFAULT_SIZE 9
using namespace std;

int main() {

    cout << "Enter the desired number of tests: ";
    int n;
    cin >> n;
    cout << "Enter the time of delay for step(in sec) during demonstration." << endl
         << "If you don't want to look on demonstrations write '0':" << endl;
    int delay;
    cin>>delay;
    delay*=1000;
    const clock_t begin_time = clock();
    for (int i = 0; i < n; i++) {
        SimulationController::StartAStarSimulation(DEFAULT_SIZE, delay);
    }
    cout<<"Average amount of time for A* algorithm: "<<float(clock() - begin_time)/CLOCKS_PER_SEC/n<<endl;


    return 0;
}