#include "graph.hpp"

void graph::addVertex(std::string x)
{
    vertex new_vertex(x);
    
    if (_vertexes.contains(new_vertex))
    {
        throw std::invalid_argument("Error: vertex already exists");
    }

    _vertexes.insert(new_vertex);
}