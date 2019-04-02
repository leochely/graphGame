#include <iostream>
#include "Graph.h"
#include <string>
#include <vector>

int main() {
    Graph graph;

    std::string choice = "";

    do{
        std::cout << "Please enter your choice" << std::endl;
        std::cin >> choice;

        if(choice == "INIT") graph.makeEmpty();
        else if (choice == "ADDV"){
            std::string vertex;
            std::cout << "Please enter a vertex name" << std::endl;
            std::cin >> vertex;
            graph.addVertex(vertex);
        }
        else if(choice == "ADDE"){
            std::string vertexTo;
            std::string vertexFrom;
            std::cout << "Please enter 2 vertices name (fromVertex then toVertex)" << std::endl;
            std::cin >> vertexTo;
            std::cin >> vertexFrom;

            int weight;
            std::cout << "Enter the weight" << std::endl;
            std::cin >> weight;
            graph.addEdge(vertexFrom, vertexTo, weight);
        }
        else if(choice == "PRINT"){
            graph.printAll();
        }
        else if(choice == "TEST1"){
            graph.makeEmpty();

            graph.addVertex("Austin");
            graph.addVertex("Dallas");
            graph.addVertex("Denver");
            graph.addVertex("Washington");
            graph.addVertex("Atlanta");
            graph.addVertex("Houston");
            graph.addVertex("Chicago");

            graph.addEdge("Austin", "Dallas", 200);
            graph.addEdge("Dallas", "Austin", 200);
            graph.addEdge("Washington", "Dallas", 1300);
            graph.addEdge("Dallas", "Denver", 780);
            graph.addEdge("Denver", "Atlanta", 1400);
            graph.addEdge("Denver", "Chicago", 1000);
            graph.addEdge("Chicago", "Denver", 1000);
            graph.addEdge("Austin", "Houston", 160);
            graph.addEdge("Atlanta", "Houston", 800);
            graph.addEdge("Houston", "Atlanta", 800);
            graph.addEdge("Washington", "Atlanta", 600);
            graph.addEdge("Atlanta", "Washington", 600);
            graph.addEdge("Dallas", "Chicago", 900);

            graph.printAll();
        }
        else if(choice == "TEST2"){

        }
        else if(choice == "PATH"){
            graph.makeEmpty();

            graph.addVertex("Austin");
            graph.addVertex("Dallas");
            graph.addVertex("Denver");
            graph.addVertex("Washington");
            graph.addVertex("Atlanta");
            graph.addVertex("Houston");
            graph.addVertex("Chicago");

            graph.addEdge("Austin", "Dallas", 200);
            graph.addEdge("Dallas", "Austin", 200);
            graph.addEdge("Washington", "Dallas", 1300);
            graph.addEdge("Dallas", "Denver", 780);
            graph.addEdge("Denver", "Atlanta", 1400);
            graph.addEdge("Denver", "Chicago", 1400);
            graph.addEdge("Chicago", "Denver", 1400);
            graph.addEdge("Austin", "Houston", 160);
            graph.addEdge("Atlanta", "Houston", 800);
            graph.addEdge("Houston", "Atlanta", 800);
            graph.addEdge("Washington", "Atlanta", 600);
            graph.addEdge("Atlanta", "Washington", 600);
            graph.addEdge("Dallas", "Chicago", 900);

            std::string fromVertex, toVertex;
            std::cout << "Enter 2 vertex names" << std::endl;
            std::cin >> fromVertex >> toVertex;
            std::vector<std::string> path;
            int minimalLength = graph.Dijkstra(fromVertex, toVertex, path);

            std::cout << "Optimal path is of length: " << minimalLength << std::endl;
        }
        else{
            std::cout << "Invalid input" << std::endl;
        }
    }while(choice != "QUIT");

    return 0;
}