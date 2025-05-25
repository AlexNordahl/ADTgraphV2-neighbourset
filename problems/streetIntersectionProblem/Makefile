CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
LDLIBS = -lgtest -lgtest_main -pthread
IMGVIEWER ?= feh

# --- Default build ---
main: main.o ../../headers/graph.o ../../headers/vertex.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# --- Rules ---
headers/graph.o: ../../headers/graph.cpp ../../headers/graph.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

headers/vertex.o: ../../headers/vertex.cpp ../../headers/vertex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp ../../headers/graph.hpp ../../headers/vertex.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Cleaning ---
clean:
	rm -f main $(wildcard *.o) graph.dot mygraph.png

# --- Run and plot ---
plot: main
	./main
	dot -Tpng graph.dot -o mygraph.png
	$(IMGVIEWER) mygraph.png