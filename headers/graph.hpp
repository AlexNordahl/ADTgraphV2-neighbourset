#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include "vertex.hpp"

class graph
{
private:
    std::unordered_map<std::string, vertex> _vertexes;
    
public:
    graph() = default;
    ~graph() = default;
    graph(const graph &rhs) = default;
    graph& operator=(const graph &rhs) = default;
    graph(graph &&rhs) = default;
    graph& operator=(graph &&rhs) = default;

    void addVertex(std::string name);
    void removeVertex(std::string name);
    void setVertexValue(std::string name, int value);
    int getVertexValue(std::string name);

    void addEdge(std::string name_x, std::string name_y);
    void removeEdge(std::string name_x, std::string name_y);
    void setEdgeValue(std::string name_x, std::string name_y, int value);
    int getEdgeValue(std::string name_x, std::string name_y);

    bool adjacent(std::string name_x, std::string y) const;
    std::vector<std::string> neighbours(std::string x) const;
    
    void printVertexes();
};

#endif