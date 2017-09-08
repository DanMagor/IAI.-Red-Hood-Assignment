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

    template<typename V, typename E = double>
    struct vertex{
        typedef pair<E, vertex*> edge;
        vector<edge> edges;
        V name;
        vertex(V s) : name(s) {}
    };

    template<typename V, typename E=double>
    class Graph {
    private:
        typedef map<V,vertex<V,E>*> vmap;
        vmap vertices;
    public:
        vector<vertex<V,E>*> GetNeighbors(vertex<V,E>);

        vector<vertex<V,E>*> GetNeighbors(V);

        void AddVertex(V);

        void AddEdge(const V , const V, E = 0.0);

        vmap GetVertices();

        vertex<V,E>* &GetVertex(V);

    };


template<typename V, typename E>
void Graph<V,E>::AddVertex(V v) {
    typename vmap::iterator itr = vertices.find(v);

    if (itr == vertices.end()) {
        vertex<V> *temp;
        temp = new vertex<V,E>(v);
        vertices[v] = temp;
    }
}

template<typename V, typename E>
void Graph<V,E>::AddEdge(const V from, const V to, E weight) {
    vertex<V,E> *f = (vertices.find(from)->second);
    vertex<V,E> *t = (vertices.find(to)->second);
    pair<E, vertex<V,E>*> edge = make_pair(weight,t);
    f->edges.push_back(edge);
}

template<typename V, typename E>
map<V,vertex<V,E>*> Graph<V,E>::GetVertices() {
    return vertices;
}


template<typename V, typename E>
vector<vertex<V, E>*> Graph<V,E>::GetNeighbors(V v) {
    vector<vertex<V,E>*> neighbors;
    for(auto t:vertices.find(v)->second->edges)
        neighbors.push_back(t.second);
    return neighbors;
}



#endif //ASSIGNMENT1_GRAPH_H
