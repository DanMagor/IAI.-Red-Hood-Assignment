//
// Created by DanMagor on 07.09.2017.
//

#ifndef ASSIGNMENT1_ASTAR_H
#define ASSIGNMENT1_ASTAR_H


#include <map>
#include <vector>
#include <unordered_map>
#include <queue>

#include "Point.h"

using namespace std;

template<typename L>
struct SimpleGraph{
    typedef L Location;
    typedef typename vector<Location>::iterator iterator;
    unordered_map<Location, vector<Location> > edges;
    inline const vector<Location> neighbors(Location id){
        return edges[id];
    }
};


class AStar {
public:
    static Point* FindPath();
};


#endif //ASSIGNMENT1_ASTAR_H
