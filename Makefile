# Makefile

make:
	g++ -std=c++20 main.cpp graph.cpp vertex.cpp -o main

clean:
	rm -f main;

test:
	cd tests; \
	g++ -std=c++20 test.cpp ../graph.cpp -lgtest -lgtest_main -pthread -o test; \
	./test; \
	rm -f test