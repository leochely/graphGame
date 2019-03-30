//
// Created by Leo on 3/13/2019.
//
#include <iostream>
#include "Graph.h"

void Graph::makeEmpty() {
    vertices.empty();
}

bool Graph::addEdge(std::string fromVertex, std::string toVertex, int weight) {
    int indexFrom = -1;
    int indexTo = -1;

    for(int i = 0; i < vertices.size(); i++){
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
    for( int i =0; i < edges.size(); i++){
        temp.push_back(-1);
    }
    edges.push_back(temp);
    for(int i = 0; i < edges.size(); i++){
        edges[i].push_back(-1);
    }
}

int Graph::getWeight(std::string fromVertex, std::string toVertex) {
    int indexFrom = -1;
    int indexTo = -1;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]== fromVertex) indexFrom = i;
        else if (vertices[i] == toVertex) indexTo = i;
    }

    if (indexFrom == -1 || indexTo ==-1) return -1;

    return edges[indexFrom][indexTo];
}

bool Graph::getAdjacent(std::string fromVertex, std::vector<std::string> &vVertex) {
    int index = -1;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i] == fromVertex) index = i; break;
    }

    if(index == -1) return false;

    for (int i = 0; i < edges[index].size(); i++){
        if(i > 0) vVertex.push_back(vertices[i]);
    }
    return true;
}

void Graph::printAll() {
    for(int i = 0; i < vertices.size(); i++){
        std::cout << vertices[i] << "; Adjacent: ";
        for(int j = 0; j< vertices.size(); j++){
            if(getWeight(vertices[i], vertices[j]) > 0)
                std::cout << vertices[j] << " (" << getWeight(vertices[i], vertices[j]) << "),";
        }
        std::cout << std::endl;
    }
}
