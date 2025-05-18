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

    _neighbors.insert(n);
}

void vertex::removeNeighbor(std::string n)
{
    _neighbors.erase(n);
}

int vertex::getValue() const
{
    return _value;
}

bool vertex::hasNeighbor(std::string n) const
{
    return _neighbors.contains(n);
}

std::string vertex::getName() const
{
    return _name;
}

std::unordered_set<std::string> vertex::getNeighbors() const
{
    return _neighbors;
}

std::string vertex::strNeighbors() const
{
    std::string result = "{ ";
    for (const auto& mem : _neighbors)
    {
        result += mem + " ";
    }
    result += "}";
    
    return result;
}

void vertex::printNeighbors() const
{
    std::cout << "{ ";
    for (const auto& elem : _neighbors)
    {
        std::cout << elem << " ";
    }
    std::cout << " }" << std::endl;
}