#include <gtest/gtest.h>
#include "../headers/vertex.hpp"

TEST(Add_and_remove_neighbors, True)
{
    vertex v1("A");

    v1.addNeighbor("B");
    v1.addNeighbor("C");
    
    v1.removeNeighbor("B");
    v1.removeNeighbor("C");

    EXPECT_TRUE(v1.hasNeighbors() == false);
}

TEST(Compare, Equals)
{
    vertex v1("A");
    v1.setValue(10);
    v1.addNeighbor("B");

    vertex v2("A");
    v2.setValue(10);
    v2.addNeighbor("B");

    EXPECT_EQ(v1, v2);
}

TEST(Copy_constructor, Equals)
{
    vertex v1("A");

    v1.setValue(10);
    v1.addNeighbor("B");
    v1.addNeighbor("C");

    vertex v2 = v1;

    EXPECT_EQ(v1, v2);
}

TEST(Copy_asg_operator, Equals)
{
    vertex v1("A");

    v1.setValue(10);
    v1.addNeighbor("B");
    v1.addNeighbor("C");

    vertex v2("C");
    v2.setValue(15);
    v2.addNeighbor("A");

    v2 = v1;

    EXPECT_EQ(v1, v2);
}

TEST(Move_constructor_first, Equals)
{
    vertex v1("A");

    v1.setValue(10);
    v1.addNeighbor("B");
    v1.addNeighbor("C");

    vertex v3 = v1;

    vertex v2 = std::move(v1);

    EXPECT_EQ(v2, v3);
}

TEST(Move_constructor_second, Equals)
{
    vertex v1("A");

    v1.setValue(10);
    v1.addNeighbor("B");
    v1.addNeighbor("C");

    vertex v3;

    vertex v2 = std::move(v1);

    EXPECT_EQ(v1, v3);
}

TEST(Move_asg_first, Equals)
{
    vertex v1("A");

    v1.setValue(10);
    v1.addNeighbor("B");
    v1.addNeighbor("C");

    vertex v3 = v1;
    vertex v2;

    v2 = std::move(v1);

    EXPECT_EQ(v2, v3);
}

TEST(Move_asg_second, Equals)
{
    vertex v1("A");

    v1.setValue(10);
    v1.addNeighbor("B");
    v1.addNeighbor("C");

    vertex v3;
    vertex v2;

    v2 = std::move(v1);

    EXPECT_EQ(v1, v3);
}