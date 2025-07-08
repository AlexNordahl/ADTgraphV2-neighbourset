#include "vertex.hpp"

vertex::vertex(const std::string &lname)
{
    name = lname;
}

vertex::vertex(const std::string &lname, const int lvalue)
{
    name = lname;
    value = lvalue;
}

bool vertex::operator==(const vertex &v) const
{
    return name == v.name;
}

bool vertex::empty()
{
    return name == "" and value == DEFAULT_VERTEX_VALUE and neighbors.empty();
}

bool vertex::hasNeighbors()
{
    return !neighbors.empty();
}

bool vertex::hasNeighbor(std::string n)
{
    return neighbors.contains(n);
}

void vertex::addNeighbor(std::string n)
{
    if (name == n)
        throw std::invalid_argument("Error: vertex cannot be neighbor to itself");

    neighbors[n] = DEFAULT_EDGE_VALUE;
}

void vertex::removeNeighbor(std::string n)
{
    if (!neighbors.contains(n))
        throw std::invalid_argument("Error: neighbor does not exist");

    neighbors.erase(n);
}

void vertex::setValue(const int v)
{
    value = v;
}

int vertex::getValue() const
{
    return value;
}

void vertex::setEdgeValue(std::string name, const int v)
{
    neighbors[name] = v;
}

int vertex::getEdgeValue(std::string name)
{
    return neighbors[name];
}

std::string vertex::getName() const
{
    return name;
}

std::unordered_map<std::string, int> vertex::getNeighbors()
{
    return neighbors;
}

std::string vertex::strNeighbors()
{
    std::string result = "{ ";
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it)
    {
        result += it->first + ": " + std::to_string(it->second);
        if (std::next(it) != neighbors.end()) {
            result += ", ";
        }
    }
    result += " }";
    
    return result;
}