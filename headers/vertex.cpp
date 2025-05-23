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

bool vertex::empty()
{
    return _name == "" and _value == DEFAULT_VERTEX_VALUE and _neighbors.empty();
}

bool vertex::hasNeighbors()
{
    return !_neighbors.empty();
}

bool vertex::hasNeighbor(std::string n)
{
    return _neighbors.contains(n);
}

void vertex::addNeighbor(std::string n)
{
    if (_name == n)
        throw std::invalid_argument("Error: vertex cannot be neighbor to itself");

    _neighbors[n] = DEFAULT_EDGE_VALUE;
}

void vertex::removeNeighbor(std::string n)
{
    if (!_neighbors.contains(n))
        throw std::invalid_argument("Error: neighbor does not exist");

    _neighbors.erase(n);
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

int vertex::getEdgeValue(std::string name)
{
    return _neighbors[name];
}

std::string vertex::getName() const
{
    return _name;
}

std::unordered_map<std::string, int> vertex::getNeighbors()
{
    return _neighbors;
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