#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <initializer_list>
#include <set>
#include "vertex.hpp"

class graph
{
private:
    std::unordered_map<std::string, vertex> _vertexes;
    
public:
    graph() = default;
    graph(std::initializer_list<std::string> list);
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

    bool adjacent(std::string name_x, std::string y);
    std::vector<std::string> neighbors(std::string x);
    
    bool empty();
    void printVertexes();
    void createDotFile(int size = 300, int dpi = 200, bool weighted = false);
    void createDotFile(bool weighted);
    void addEdges(std::string name_x, std::initializer_list<std::string> list);
    std::vector<std::string> getAllVertices();
};

#endif