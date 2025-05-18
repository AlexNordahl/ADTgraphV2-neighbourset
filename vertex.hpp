#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <unordered_set>
#include <functional>

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
    
    bool operator==(const vertex &v) const;

    void addNeighbor(std::string n);
    void removeNeighbor(std::string n);
    bool hasNeighbor(std::string n) const;
    std::string getName() const;
    std::unordered_set<std::string> getNeighbors() const;

    void printNeighbors() const;
};

namespace std 
{
    template<>
    struct hash<vertex> 
    {
        std::size_t operator()(const vertex& v) const 
        {
            std::cout << std::hash<std::string>()(v.getName()) << std::endl;
            return std::hash<std::string>()(v.getName());
        }
    };
}


#endif