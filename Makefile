# Makefile

make:
	g++ -std=c++20 main.cpp headers/graph.cpp headers/vertex.cpp -o main

clean:
	rm -f main;

test_vertex:
	cd tests; \
	g++ -std=c++20 test_vertex.cpp ../headers/vertex.cpp -lgtest -lgtest_main -pthread -o test_vertex; \
	./test_vertex; \
	rm -f test_vertex

test_graph:
	cd tests; \
	g++ -std=c++20 test_graph.cpp ../headers/vertex.cpp ../headers/graph.cpp -lgtest -lgtest_main -pthread -o test_graph; \
	./test_graph; \
	rm -f test_graph