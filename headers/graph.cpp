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

void graph::removeVertex(std::string x)
{
    _vertexes.erase(vertex(x));
}

void graph::setVertexValue(std::string x, int v)
{
    if (!_vertexes.contains(vertex(x)))
        throw std::invalid_argument("Error: cannot set value of a vertex that does not exist");

    vertex new_vertex(x, v);
    removeVertex(x);
    _vertexes.insert(new_vertex);
}

int graph::getVertexValue(std::string x)
{
    auto it = _vertexes.find(x);
    return it->getValue();
}

void graph::printVertexes()
{
    for (const auto& vertex : _vertexes)
    {
        std::cout << vertex.getName();
        std::cout << ": " << vertex.strNeighbors() << std::endl;
    }
}