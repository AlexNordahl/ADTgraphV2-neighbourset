#include "headers/graph.hpp"

int main() 
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.addEdges("A", {"B", "C"});

    g.createDotFile(false);

    return 0;
}
