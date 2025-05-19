#include "headers/graph.hpp"

int main(int argc, char const *argv[])
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    
    g.setVertexValue("A", 10);
    g.setVertexValue("B", 15);

    g.addEdge("A", "B");
    g.addEdge("B", "C");
    g.addEdge("A", "D");

    g.setEdgeValue("A", "B", 10);
    g.setEdgeValue("C", "B", 15);
    g.setEdgeValue("A", "D", 20);

    g.printVertexes();

    return 0;
}