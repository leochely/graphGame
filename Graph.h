//
// Created by Leo on 3/13/2019.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <string>
#include <vector>

class Graph {
public:
    Graph(){;};
    void makeEmpty();
    void addVertex(std::string vertexName);
    bool addEdge(std::string fromVertex, std::string toVertex, int weight);
    int getWeight(std::string fromVertex, std::string toVertex);
    bool getAdjacent(std::string fromVertex, std::vector<std::string> &vVertex);
    int Dijkstra(std::string startVertex, std::string endVertex, std::vector<std::string> &vVertex);
    void printAll();
private:
    std::vector<std::string> vertices;
    std::vector<std::vector<int>> edges;
};


#endif //GRAPH_GRAPH_H
