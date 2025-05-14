#include "vertex.hpp"

vertex::vertex(const std::string &name)
{
    _name = name;
}

vertex::vertex(const vertex &rhs)
{
    _neighbors = rhs._neighbors;
}

vertex &vertex::operator=(const vertex &rhs)
{
    _neighbors = rhs._neighbors;
    
    return *this;
}

vertex::vertex(vertex &&rhs)
{
    _neighbors = std::move(rhs._neighbors);
}

vertex &vertex::operator=(vertex &&rhs)
{
    if (this == &rhs)
        return *this;

    _neighbors = std::move(rhs._neighbors);

    return *this;
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

bool vertex::hasNeighbor(std::string n)
{
    return _neighbors.contains(n);
}

std::unordered_set<std::string> vertex::getNeighbors()
{
    return _neighbors;
}

void vertex::printNeighbors()
{
    for (const auto& elem : _neighbors)
        std::cout << elem << " ";
    std::cout << std::endl;
}