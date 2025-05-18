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
    graph& operator=(const graph &rhs);
    graph(graph &&rhs);
    graph& operator=(graph &&rhs);

    void addVertex(std::string x);
    void removeVertex(std::string x);
    void setVertexValue(std::string x, int v);
    int getVertexValue(std::string x) const;

    void addEdge(std::string x, std::string y);
    void addEdge(std::string x, std::string y, int v);
    void removeEdge(std::string x, std::string y);
    void setEdgeValue(std::string x, std::string y, int v);
    int getEdgeValue(std::string x, std::string y) const;

    bool adjacent(std::string x, std::string y) const;
    std::vector<std::string> neighbours(std::string x) const;
    
    void printMatrix();
    void printVertexes();
    std::string getVertexes();
    std::string getEdges();
    void createDotFile();
};

#endif