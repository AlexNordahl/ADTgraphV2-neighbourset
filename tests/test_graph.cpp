#include <gtest/gtest.h>
#include "../headers/graph.hpp"

TEST(Add_remove, True)
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");

    g.removeVertex("B");
    g.removeVertex("C");
    g.removeVertex("A");

    EXPECT_TRUE(g.empty());
}

TEST(Vertex_values, True)
{
    graph g;

    g.addVertex("A");
    
    g.setVertexValue("A", 10);

    EXPECT_EQ(g.getVertexValue("A"), 10);
}

TEST(Edges_add, Equals)
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");

    g.addEdge("A", "B");
    g.addEdge("B", "C");

    std::vector<std::string> expected {"C"};
    EXPECT_EQ(g.neighbors("B"), expected);
}

TEST(Edges_values, Equals)
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");

    g.addEdge("A", "B");
    g.addEdge("B", "C");

    g.setEdgeValue("A", "B", 15);

    EXPECT_EQ(g.getEdgeValue("A", "B"), 15);
}

TEST(Adjacent, True)
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");

    g.addEdge("A", "B");
    g.addEdge("B", "C");

    EXPECT_TRUE(g.adjacent("A", "B") and g.adjacent("B", "C"));
}

TEST(Neighbors, Equals)
{
    graph g;

    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.addEdge("A", "B");
    g.addEdge("B", "C");
    g.addEdge("B", "D");

    std::vector<std::string> temp {"D", "C"};
    EXPECT_EQ(g.neighbors("B"), temp);
}