#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <unordered_set>
#include <functional>

#define DEFAULT_VERTEX_VALUE 1
#define DEFAULT_EDGE_VALUE 1

class vertex
{
private:
    std::unordered_map<std::string, int> _neighbors {};
    std::string _name {};
    int _value {DEFAULT_VERTEX_VALUE};
    
public:
    vertex() = default;
    vertex(const std::string& name);
    vertex(const std::string& name, const int value);
    ~vertex() = default;
    vertex(const vertex &v) = default;
    vertex& operator=(const vertex &v) = default;
    vertex(vertex &&v) = default;
    vertex& operator=(vertex &&v) = default;
    
    bool operator==(const vertex &v) const;

    bool empty();
    bool hasNeighbors();
    bool hasNeighbor(std::string n);
    void addNeighbor(std::string n);
    void removeNeighbor(std::string n);
    void setValue(const int v);
    int getValue() const;
    void setEdgeValue(std::string name, const int v);
    int getEdgeValue(std::string name);
    
    std::string getName() const;
    std::unordered_map<std::string, int> getNeighbors();
    std::string strNeighbors();
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