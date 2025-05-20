#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "headers/graph.hpp"

int main() 
{
    std::ofstream outfile("vertex_times.txt");
    
    const int max_vertices = 10000;
    const int step = 10;
    const int repeats = 50;

    for (int current_size = step; current_size <= max_vertices; current_size += step) 
    {
        double total_time_us = 0.0;

        for (int i = 0; i < repeats; ++i) {
            graph g;

            for (int j = 1; j < current_size; ++j) 
            {
                g.addVertex("V" + std::to_string(j));
            }

            auto start = std::chrono::high_resolution_clock::now();

            g.addVertex("V" + std::to_string(current_size));

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::micro> duration = end - start;

            total_time_us += duration.count();
        }

        double avg_time = total_time_us / repeats;
        outfile << current_size << " " << avg_time << "\n";
    }

    outfile.close();

    return 0;
}
