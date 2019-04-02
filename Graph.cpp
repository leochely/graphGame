//
// Created by Leo on 3/13/2019.
//
#include <iostream>
#include "Graph.h"
#include <climits>

void Graph::makeEmpty() {
    vertices.empty();
}

bool Graph::addEdge(std::string fromVertex, std::string toVertex, int weight) {
    int indexFrom = -1;
    int indexTo = -1;

    for(int i = 0; i < vertices.size(); ++i){
        if(vertices[i]== fromVertex) indexFrom = i;
        else if (vertices[i] == toVertex) indexTo = i;
    }

    if (indexFrom == -1 || indexTo ==-1) return false;
    edges[indexTo][indexFrom] = weight;
    return true;
}

void Graph::addVertex(std::string vertexName) {
    vertices.push_back(vertexName);
    std::vector<int> temp;
    for( int i =0; i < edges.size(); ++i){
        temp.push_back(-1);
    }
    edges.push_back(temp);
    for(int i = 0; i < edges.size(); ++i){
        edges[i].push_back(-1);
    }
}

int Graph::getWeight(std::string fromVertex, std::string toVertex) {
    int indexFrom = -1;
    int indexTo = -1;

    for(int i = 0; i < vertices.size(); ++i){
        if(vertices[i]== fromVertex) indexFrom = i;
        else if (vertices[i] == toVertex) indexTo = i;
    }

    if (indexFrom == -1 || indexTo ==-1) return -1;

    return edges[indexFrom][indexTo];
}

bool Graph::getAdjacent(std::string fromVertex, std::vector<std::string> &vVertex) {
    int index = -1;

    for(int i = 0; i < vertices.size(); ++i){
        if(vertices[i] == fromVertex) index = i; break;
    }

    if(index == -1) return false;

    for (int i = 0; i < edges[index].size(); ++i){
        if(i > 0) vVertex.push_back(vertices[i]);
    }
    return true;
}

void Graph::printAll() {
    for(int i = 0; i < vertices.size(); ++i){
        std::cout << vertices[i] << "; Adjacent: ";
        for(int j = 0; j< vertices.size(); j++){
            if(getWeight(vertices[i], vertices[j]) > 0)
                std::cout << vertices[j] << " (" << getWeight(vertices[i], vertices[j]) << "),";
        }
        std::cout << std::endl;
    }
}


int Graph::Dijkstra(std::string fromVertex, std::string toVertex, std::vector<std::string> &vVertex) {

    std::vector<int> distances;
    std::vector<std::string> spt;
    std::vector<int> parents(vertices.size(), 0);
    int indexFrom = -1;
    int indexTo = -1;


    for(int i = 0; i < vertices.size(); ++i){
        if(vertices[i]== fromVertex) indexFrom = i;
        else if (vertices[i] == toVertex) indexTo = i;
    }

    if(indexFrom == 0 || indexTo == 0){
        return -1;
    }

    for(auto &vertex: vertices){
        if(vertex == fromVertex){
            distances.push_back(0);
            continue;
        }
        distances.push_back(INT_MAX);
    }

    while(spt.size() < vertices.size()){
        int min = distances[0];
        int index = 0;
        for(int i=0; i < distances.size(); ++i){
            if (distances[i] < min){
                min = distances[i];
                index = i;
            }
        }

        spt.push_back(vertices[index]);

        std::vector<std::string> adjacents;
        getAdjacent(vertices[index], adjacents);
        for(auto &vertex: adjacents){
            for(int i = 0; i < vertices.size(); ++i) {
                if (vertex == vertices[i] && distances[i] > getWeight(vertices[index], vertices[i])) {
                    distances[i] = getWeight(vertices[index], vertices[i]);
                    parents[i] = index;
                }
            }
        }
    }

    if(distances[indexTo] == INT_MAX) return -1;

    std::string currentVertex = toVertex;
    int index = indexTo;
    do{
        vVertex.push_back(currentVertex);
        currentVertex = vertices[parents[index]];
        index = parents[index];
    }while(currentVertex != fromVertex);

    return distances[indexTo];
}