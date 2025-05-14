#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <unordered_set>

class vertex
{
private:
    std::unordered_set<std::string> _neighbors;

public:
    vertex() = default;
    ~vertex() = default;
    vertex(const vertex &v);
    vertex& operator=(const vertex &v);
    vertex(vertex &&v);
    vertex& operator=(vertex &&v);

    void insertNeighbor(std::string n);
    void eraseNeighbor(std::string n);
    std::unordered_set<std::string> getNeighbors();

    void printNeighbors()
    {
        for (const auto& elem : _neighbors)
            std::cout << elem << " ";
        std::cout << std::endl;
    }
};

#endif