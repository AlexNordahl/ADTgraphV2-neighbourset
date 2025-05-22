#include "../headers/graph.hpp"

int main()
{
    graph crossing {"A", "B", "C", "D", "E"};

    crossing.addEdges("A", {"B", "D", "E"});
    crossing.addEdges("B", {"A", "D", "E"});
    crossing.addEdges("D", {"A", "B", "E"});
    crossing.addEdges("E", {"A", "B", "D"});

    crossing.createDotFile(300, 200, false);

    return 0;
}
