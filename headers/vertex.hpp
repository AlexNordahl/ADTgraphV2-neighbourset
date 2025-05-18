#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <unordered_set>
#include <functional>

#define DEFAULT_VERTEX_VALUE 1

class vertex
{
private:
    std::unordered_set<std::string> _neighbors {};
    std::string _name {};
    int _value {DEFAULT_VERTEX_VALUE};
    
public:
    vertex() = delete;
    vertex(const std::string& name);
    vertex(const std::string& name, const int value);
    ~vertex() = default;
    vertex(const vertex &v) = default;
    vertex& operator=(const vertex &v) = default;
    vertex(vertex &&v) = default;
    vertex& operator=(vertex &&v) = default;
    
    bool operator==(const vertex &v) const;

    void addNeighbor(std::string n);
    void removeNeighbor(std::string n);
    int getValue() const;
    bool hasNeighbor(std::string n) const;
    std::string getName() const;
    std::unordered_set<std::string> getNeighbors() const;

    std::string strNeighbors() const;
    void printNeighbors() const;
};

namespace std 
{
    template<>
    struct hash<vertex> 
    {
        std::size_t operator()(const vertex& v) const 
        {
            return std::hash<std::string>()(v.getName());
        }
    };
}


#endif