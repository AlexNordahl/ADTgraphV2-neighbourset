CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
LDLIBS = -lgtest -lgtest_main -pthread
IMGVIEWER ?= feh

# --- Default build ---
main: main.o headers/graph.o headers/vertex.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# --- Rules ---
headers/graph.o: headers/graph.cpp headers/graph.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

headers/vertex.o: headers/vertex.cpp headers/vertex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp headers/graph.hpp headers/vertex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Cleaning ---
clean:
	rm -f main $(wildcard *.o) $(wildcard headers/*.o) graph.dot mygraph.png
	$(MAKE) -C problems/streetIntersection clean
	$(MAKE) -C problems/theKnightsTour clean
	$(MAKE) -C problems/wordLadder clean

# --- Run and plot ---
plot: main
	./main
	dot -Tpng graph.dot -o mygraph.png
	$(IMGVIEWER) mygraph.png

# --- Unit tests ---
test_vertex:
	$(CXX) $(CXXFLAGS) tests/test_vertex.cpp headers/vertex.cpp -o test_vertex $(LDLIBS)
	./test_vertex
	rm -f test_vertex

test_graph:
	$(CXX) $(CXXFLAGS) tests/test_graph.cpp headers/graph.cpp headers/vertex.cpp -o test_graph $(LDLIBS)
	./test_graph
	rm -f test_graph

# --- Subprojects ---
knightproblem:
	$(MAKE) -C problems/theKnightsTour plot

streetproblem:
	$(MAKE) -C problems/streetIntersection plot

ladderproblem:
	$(MAKE) -C problems/wordLadder plot