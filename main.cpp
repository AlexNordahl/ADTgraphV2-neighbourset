#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "headers/graph.hpp"

int main() 
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.addEdge("A", "B");
    g.addEdge("B", "C");
    g.addEdge("B", "D");

    g.createDotFile();

    return 0;
}
