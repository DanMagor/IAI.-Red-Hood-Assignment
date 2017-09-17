//
// Created by DanMagor on 07.09.2017.
//

#ifndef ASSIGNMENT1_ASTAR_H
#define ASSIGNMENT1_ASTAR_H


#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include "Graph.h"

using namespace std;
typedef pair<int, int> point;

class AStar {
private:
    static stack<point> ConvertMapToStack(map<point, point>, point, point);

    template<typename T, typename priority_t>
    struct PriorityQueue {
        typedef pair<priority_t, T> PQElement;
        priority_queue<PQElement, vector<PQElement>,std::greater<PQElement>> elements;

        inline bool empty() const { return elements.empty(); }

        inline void put(T item, priority_t priority) {
            elements.emplace(priority, item);
        }

        inline T get() {
            T best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    };

public:
    static stack<point> FindPath(Graph<pair<int, int>> &, pair<int, int>, pair<int, int>);
};


#endif //ASSIGNMENT1_ASTAR_H
