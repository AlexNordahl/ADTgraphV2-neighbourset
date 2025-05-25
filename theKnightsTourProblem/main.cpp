#include "../headers/graph.hpp"

int countUnvisitedNeighbors(graph& g, const std::string& vertex, const std::unordered_set<std::string>& visited) 
{
    int count = 0;
    for (const auto& neighbor : g.neighbors(vertex)) 
    {
        if (visited.find(neighbor) == visited.end()) 
        {
            count++;
        }
    }
    return count;
}

std::vector<std::string> findKnightTour(graph& g, const std::string& start) 
{
    std::unordered_set<std::string> visited;
    std::vector<std::string> path;
    int totalVertices = g.getAllVertices().size();

    std::function<bool(const std::string&)> dfs = [&](const std::string& current) -> bool {
        visited.insert(current);
        path.push_back(current);

        if (path.size() == totalVertices) {
            return true;
        }

        std::vector<std::string> neighbors;
        for (const auto& neighbor : g.neighbors(current)) 
        {
            if (visited.find(neighbor) == visited.end()) 
            {
                neighbors.push_back(neighbor);
            }
        }

        std::sort(neighbors.begin(), neighbors.end(), [&](const std::string& a, const std::string& b) 
        {
            return countUnvisitedNeighbors(g, a, visited) < countUnvisitedNeighbors(g, b, visited);
        });

        for (const auto& next : neighbors) 
            if (dfs(next)) return true;

        visited.erase(current);
        path.pop_back();
        return false;
    };

    if (dfs(start)) 
        return path;
    else 
        return {};
}

int main()
{
    graph chessboard;
    int chessboard_size = 8;

    for (size_t x = 1; x <= chessboard_size; ++x)
        for (size_t y = 1; y <= chessboard_size; ++y)
            chessboard.addVertex(std::to_string(x) + "_" + std::to_string(y));
    
    std::vector<int> moves_x {2, 2, -2, -2, 1, 1, -1, -1};
    std::vector<int> moves_y {1, -1, 1, -1, 2, -2, 2, -2};

    for (size_t x = 1; x <= chessboard_size; ++x) 
    {
        for (size_t y = 1; y <= chessboard_size; ++y) 
        {
            std::string from = std::to_string(x) + "_" + std::to_string(y);
            for (size_t i = 0; i < moves_x.size(); ++i) 
            {
                int nx = x + moves_x[i];
                int ny = y + moves_y[i];

                if (nx >= 1 && ny >= 1 && nx <= chessboard_size && ny <= chessboard_size) 
                {
                    std::string to = std::to_string(nx) + "_" + std::to_string(ny);
                    chessboard.addEdge(from, to);
                }
            }
        }
    }

    std::vector<std::string> path = findKnightTour(chessboard, "1_1");

    for (const auto& elem : path)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    chessboard.createDotFile();

    return 0;
}
