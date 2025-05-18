#include "vertex.hpp"

vertex::vertex(const std::string &name)
{
    _name = name;
}

vertex::vertex(const vertex &rhs)
{
    _name = rhs._name;
    _neighbors = rhs._neighbors;
}

vertex &vertex::operator=(const vertex &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        _neighbors = rhs._neighbors;
    }
    
    return *this;
}

vertex::vertex(vertex &&rhs)
{
    _name = std::move(rhs._name);
    _neighbors = std::move(rhs._neighbors);
}

vertex &vertex::operator=(vertex &&rhs)
{
    if (this == &rhs)
        return *this;

    _name = std::move(rhs._name);
    _neighbors = std::move(rhs._neighbors);

    return *this;
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

void vertex::printNeighbors() const
{
    for (const auto& elem : _neighbors)
        std::cout << elem << " ";
    std::cout << std::endl;
}