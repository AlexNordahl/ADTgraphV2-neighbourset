#include "vertex.hpp"

int main(int argc, char const *argv[])
{
    vertex v1;
    
    v1.insertNeighbor("A");
    v1.insertNeighbor("B");
    v1.insertNeighbor("C");

    vertex v2 = v1;

    v2.printNeighbors();

    return 0;
}