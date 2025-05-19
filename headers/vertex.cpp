#include "vertex.hpp"

vertex::vertex(const std::string &name)
{
    _name = name;
}

vertex::vertex(const std::string &name, const int value)
{
    _name = name;
    _value = value;
}

bool vertex::operator==(const vertex &v) const
{
    return _name == v._name;
}

void vertex::addNeighbor(std::string n)
{
    if (_name == n)
        throw std::invalid_argument("Error: vertex cannot be neighbor to itself");

    _neighbors[n] = DEFAULT_EDGE_VALUE;
}

void vertex::removeNeighbor(std::string n)
{
    _neighbors[n] = DEFAULT_EDGE_VALUE;
}

void vertex::setValue(const int v)
{
    _value = v;
}

int vertex::getValue() const
{
    return _value;
}

void vertex::setEdgeValue(std::string name, const int v)
{
    _neighbors[name] = v;
}

std::string vertex::getName() const
{
    return _name;
}

std::string vertex::strNeighbors()
{
    std::string result = "{ ";
    for (auto it = _neighbors.begin(); it != _neighbors.end(); ++it)
    {
        result += it->first + ": " + std::to_string(it->second);
        if (std::next(it) != _neighbors.end()) {
            result += ", ";
        }
    }
    result += " }";
    
    return result;
}