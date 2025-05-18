#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include "vertex.hpp"

class graph
{
private:
    std::unordered_set<vertex> _vertexes;
    
public:
    graph() = default;
    ~graph() = default;
    graph(const graph &rhs) = default;
    graph& operator=(const graph &rhs) = default;
    graph(graph &&rhs) = default;
    graph& operator=(graph &&rhs) = default;

    void addVertex(std::string v);
    void removeVertex(std::string v);
    void setVertexValue(std::string x, int v);
    int getVertexValue(std::string x);

    void addEdge(std::string x, std::string y);
    void addEdge(std::string x, std::string y, int v);
    void removeEdge(std::string x, std::string y);
    void setEdgeValue(std::string x, std::string y, int v);
    int getEdgeValue(std::string x, std::string y) const;

    bool adjacent(std::string x, std::string y) const;
    std::vector<std::string> neighbours(std::string x) const;
    
    void printVertexes();
};

#endif