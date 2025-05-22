# Makefile

make:
	g++ -std=c++20 main.cpp headers/graph.cpp headers/vertex.cpp -o main

clean:
	rm -f main; \
	rm -f graph.dot; \
	rm -f mygraph.png

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

plot:
	make; \
	./main; \
	dot -Tpng graph.dot -o mygraph.png; \
	feh mygraph.png