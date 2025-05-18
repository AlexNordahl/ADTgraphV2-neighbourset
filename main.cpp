#include "headers/graph.hpp"

int main(int argc, char const *argv[])
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    
    g.setVertexValue("A", 10);
    g.setVertexValue("B", 15);

    g.printVertexes();

    return 0;
}