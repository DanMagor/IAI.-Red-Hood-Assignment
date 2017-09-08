//
// Created by DanMagor on 07.09.2017.
//

#ifndef ASSIGNMENT1_GRAPH_H
#define ASSIGNMENT1_GRAPH_H

#include <vector>
#include <map>
#include <c++/4.8.3/iostream>
#include "Point.h"

using namespace std;



    template<typename V, typename E=double>
    class Graph {


        typedef struct vertex {
            typedef pair<E, vertex *> edge;
            vector<edge> edges;
            V name;

            vertex(V s) : name(s) {}
        } vertex;

    private:
        typedef map<V, vertex *> vmap;
        vmap vertices;
    public:
        void AddVertex(V v) {
            typename vmap::iterator itr = vertices.find(v);

            if (itr == vertices.end()) {
                vertex *temp;
                temp = new vertex(v);
                vertices[v] = temp;
            }
        }

        void AddEdge(const V from, const V to, E weight=0.0) {
            vertex *f = (vertices.find(from)->second);
            vertex *t = (vertices.find(to)->second);
            pair<E, vertex *> edge = make_pair(weight, t);
            f->edges.push_back(edge);
        }

        vmap GetVertices() {
            return vertices;
        }

        vector<vertex *> GetNeighbors(V v) {
            vector<vertex *> neighbors;
            for (auto t:vertices.find(v)->second->edges)
                neighbors.push_back(t.second);
            return neighbors;
        }


        vertex *&GetVertex(V);

    };

#endif //ASSIGNMENT1_GRAPH_H
