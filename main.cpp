#include "vertex.hpp"

int main(int argc, char const *argv[])
{
    vertex v1("A");
    
    v1.addNeighbor("B");
    v1.addNeighbor("C");
    v1.addNeighbor("D");

    vertex v2 = v1;

    v2.printNeighbors();

    return 0;
}