//
// Created by DanMagor on 07.09.2017.
//Simple Graph Template Implementation
//

#ifndef ASSIGNMENT1_GRAPH_H
#define ASSIGNMENT1_GRAPH_H

#include <vector>
#include <map>
#include <c++/4.8.3/iostream>


using namespace std;


template<typename V, typename E=double>
class Graph {


    struct vertex {
        typedef pair<E, vertex *> edge;
        vector<edge> edges;
        V name;

        vertex(V s) : name(s) {}
    };

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

    void AddEdge(const V from, const V to, E weight = 0.0) {  //add edge from vertex 'from' to vertex 'to' with weight
        vertex *f = (vertices.find(from)->second);
        vertex *t = (vertices.find(to)->second);
        pair<E, vertex *> edge = make_pair(weight, t);
        f->edges.push_back(edge);
    }

    vmap GetVertices() {
        return vertices;
    }

    vector<V> GetNeighbors(pair<int, int> v)  {  //return Neighbors of vertex V
        vector<V> neighbors;
        for (typename Graph::vertex::edge t:vertices.find(v)->second->edges) {
            neighbors.push_back(t.second->name);
        }
        return neighbors;
    }

    void DeleteVertex(V deleted_vertex) {
        for (auto v: vertices) {
            int i = 0;
            for (auto e: v.second->edges){
                if(e.second->name == deleted_vertex){
                    v.second->edges.erase(v.second->edges.begin()+i);
                }
                i++;
            }
        }
        vertices.erase(deleted_vertex);
    }

    double GetEdgeWeight(pair<int, int> v1, pair<int, int> v2) {
        for(auto e: vertices[v1]->edges){
            if (e.second->name == v2){
                return e.first;
            }
        }
    }

    void SetEdgeWeight(V v1, V v2, E weight){
        if (vertices.find(v1) != vertices.end()){
            for(auto &e: vertices[v1]->edges){
                if (e.second->name == v2){
                    e.first = weight;
                }
            }
        }

    }

    vertex *&GetVertex(V);  //TODO: Implement

};

#endif //ASSIGNMENT1_GRAPH_H
