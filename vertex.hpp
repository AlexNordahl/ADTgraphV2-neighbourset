#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <unordered_set>

class vertex
{
private:
    std::string _name {};
    std::unordered_set<std::string> _neighbors {};

public:
    vertex() = delete;
    vertex(const std::string& name);
    ~vertex() = default;
    vertex(const vertex &v);
    vertex& operator=(const vertex &v);
    vertex(vertex &&v);
    vertex& operator=(vertex &&v);

    void addNeighbor(std::string n);
    void removeNeighbor(std::string n);
    bool hasNeighbor(std::string n);
    std::unordered_set<std::string> getNeighbors();

    void printNeighbors();
};

#endif