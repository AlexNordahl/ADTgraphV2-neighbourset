#include "graph.hpp"

graph::graph(std::initializer_list<std::string> list)
{
    for (const std::string& name : list)
        addVertex(name);
}

void graph::addVertex(std::string name)
{
    if (_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex already exists");
    
    _vertexes[name] = vertex(name);
}

void graph::removeVertex(std::string name)
{
    if (!_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex doesn't exist");
    
    _vertexes.erase(name);
}

void graph::setVertexValue(std::string name, int value)
{
    if (!_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex doesn't exist");

    _vertexes[name].setValue(value);
}

int graph::getVertexValue(std::string name)
{
    if (!_vertexes.contains(name))
        throw std::invalid_argument("Error: vertex doesn't exist");

    return _vertexes[name].getValue();
}


void graph::addEdge(std::string name_x, std::string name_y)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");

    _vertexes[name_x].addNeighbor(name_y);
}

void graph::removeEdge(std::string name_x, std::string name_y)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");

    _vertexes[name_x].removeNeighbor(name_y);
}

void graph::setEdgeValue(std::string name_x, std::string name_y, int value)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");
    
    for (auto& pair : _vertexes)
    {
        if (pair.first == name_x)
            pair.second.setEdgeValue(name_y, value);
    }
}

int graph::getEdgeValue(std::string name_x, std::string name_y)
{
    if (!_vertexes.contains(name_x) or !_vertexes.contains(name_y))
        throw std::invalid_argument("Error: vertex doesn't exist");

    return _vertexes[name_x].getEdgeValue(name_y);
}

bool graph::adjacent(std::string name_x, std::string name_y)
{
    return _vertexes[name_x].hasNeighbor(name_y) or _vertexes[name_y].hasNeighbor(name_x);
}

std::vector<std::string> graph::neighbors(std::string x)
{
    std::unordered_map nb = _vertexes[x].getNeighbors();
    std::vector<std::string> result;

    for (auto& pair : nb)
    {
        result.push_back(pair.first);
    }
    
    return result;
}

bool graph::empty()
{
    return _vertexes.empty();
}

void graph::printVertexes()
{
    for (auto name_vertex_pair : _vertexes)
    {
        std::cout << name_vertex_pair.first << ": " << name_vertex_pair.second.strNeighbors() << std::endl;
    }
}

void graph::createDotFile(int size, int dpi, bool weighted)
{
    std::ofstream dotFile("graph.dot");

    dotFile << "digraph {\n";
    dotFile << "\tsize=\"" << size << "," << size << "\";\n";
    dotFile << "\tdpi=" << dpi << ";\n";

    std::set<std::pair<std::string, std::string>> addedEdges;

    for (auto& pair : _vertexes)
    {
        for (auto& n : pair.second.getNeighbors())
        {
            std::string from = pair.first;
            std::string to = n.first;

            addedEdges.insert({from, to});
        }
    }

    for (const auto& pair : addedEdges)
    {
        if (addedEdges.contains({pair.second, pair.first}))
        {
            dotFile << "\t\"" << pair.first << "\" -> \"" << pair.second << "\" [dir=\"both\"];\n";
            addedEdges.erase({pair.second, pair.first});
            continue;
        }
        
        dotFile << "\t\"" << pair.first << "\" -> \"" << pair.second << "\";\n";
    }

    dotFile << "}";
    
    dotFile.close();
}

void graph::addEdges(std::string name_x, std::initializer_list<std::string> list)
{
    for (auto& name : list)
    {
        addEdge(name_x, name);
    }
    
}
