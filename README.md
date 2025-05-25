# ADT Graph V2

Simple implementation of graph data structure.

## Description

This solution uses vertex class which directly stores neighbors of particular node. This approach improves overall space complexity. Adding and deleting nodes is also faster because it's no longer required to readjust matrix size. Solution follows best practices like rule of 5.

Implemented functionalities:
- **addVertex** - adds vertex with name
- **removeVertex** - removes specific vertex
- **setVertexValue** - set vertex value (default 1)
- **getVertexValue** - get vertex value
- **addEdge** add edge between two nodes
- **removeEdge** removes edge
- **setEdgeValue** set edge value (default 1)
- **getEdgeValue** get edge value
- **adjacent** returns true if two nodes have edge
- **neighbors** returns vector of all node neighbors
- **createdDotFile** creates file name mygraph.dot, size and dpi can be specified

## Getting Started

* Simply include graph.hpp.

### Dependencies

* Library doesn't require any external libraries and tools.
* Makefile commands require **gtest**, **dot** and **feh**.

## Authors

Alexander Nordahl