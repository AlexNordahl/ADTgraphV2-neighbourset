#include "../headers/graph.hpp"

int main()
{
    graph crossing {
        "A-D", "D-A", "D-B", "D-C",
        "A-B", "A-C", "B-A",
        "E-D", "E-A", "E-B", "E-C",
        "B-C", "B-D"
    };

    crossing.addEdges("A-D", {"E-B", "A-C", "A-B", "B-A", "E-C", "E-D"});
    crossing.addEdges("D-A", {"E-B", "A-C", "A-B", "E-C", "B-C", "B-A", "E-D", "E-A"});
    crossing.addEdges("D-B", {"E-B", "E-C", "B-C", "B-D", "A-C"});
    crossing.addEdges("D-C", {"B-A", "E-B"});
    crossing.addEdges("A-B", {"A-D", "E-C", "B-A", "E-D", "E-A", "D-A", "B-C"});
    crossing.addEdges("A-C", {"B-A", "A-D", "D-A", "D-B", "E-C", "B-C", "B-D"});
    crossing.addEdges("B-A", {"B-C", "E-C", "D-A", "D-A", "A-B", "A-C", "D-C", "E-B"});
    crossing.addEdges("E-D", {"D-A", "A-D", "A-B", "B-C", "E-C"});
    crossing.addEdges("E-A", {"D-A", "B-C", "A-B"});
    crossing.addEdges("E-B", {"A-D", "D-A", "D-B", "B-A", "D-C"});
    crossing.addEdges("E-C", {"D-B", "D-A", "A-D", "B-A", "E-D", "A-B", "A-C"});
    crossing.addEdges("B-C", {"D-B", "D-A", "A-C", "A-B", "B-A", "E-D", "E-A"});
    crossing.addEdges("B-D", {"D-B", "A-C"});

    crossing.createDotFile(150, 100, false);

    return 0;
}
