#include "vertex.hpp"

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

void vertex::insertNeighbor(std::string n)
{
    _neighbors.insert(n);
}

void vertex::eraseNeighbor(std::string n)
{
    _neighbors.erase(n);
}

std::unordered_set<std::string> vertex::getNeighbors()
{
    return _neighbors;
}
