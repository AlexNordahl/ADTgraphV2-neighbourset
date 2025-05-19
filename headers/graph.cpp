#include "graph.hpp"

void graph::addVertex(std::string name)
{
    if (_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex already exists");
    
    _vertexes[name] = vertex(name);
}

void graph::removeVertex(std::string name)
{
    if (!_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex doesn't exist");
    
    _vertexes.erase(name);
}

void graph::setVertexValue(std::string name, int value)
{
    if (!_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex doesn't exist");

    _vertexes[name].setValue(value);
}

int graph::getVertexValue(std::string name)
{
    if (!_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex doesn't exist");

    return _vertexes[name].getValue();
}


void graph::addEdge(std::string name_x, std::string name_y)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");

    _vertexes[name_x].addNeighbor(name_y);
    _vertexes[name_y].addNeighbor(name_x);
}

void graph::removeEdge(std::string name_x, std::string name_y)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");

    _vertexes[name_x].removeNeighbor(name_y);
    _vertexes[name_y].removeNeighbor(name_x);
}

void graph::setEdgeValue(std::string name_x, std::string name_y, int value)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");

    _vertexes[name_x].setEdgeValue(name_y, value);
    _vertexes[name_y].setEdgeValue(name_x, value);
}

int graph::getEdgeValue(std::string name_x, std::string name_y)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");

    return _vertexes[name_x].getValue();
}

void graph::printVertexes()
{
    for (auto name_vertex_pair : _vertexes)
    {
        std::cout << name_vertex_pair.first << ": " << name_vertex_pair.second.strNeighbors() << std::endl;
    }
}