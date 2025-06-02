#include <iostream>
#include <fstream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_set<std::string> load_words(const std::string& filename)
{
    std::unordered_set<std::string> words;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return words;
    }

    std::string word;
    while (std::getline(file, word))
    {
        if (word.length() == 4)
        {
            words.insert(word);
        }
    }

    return words;
}

bool one_letter_diff(const std::string& a, const std::string& b)
{
    int diff = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (a[i] != b[i]) ++diff;
        if (diff > 1) return false;
    }
    return diff == 1;
}

std::unordered_map<std::string, std::vector<std::string>> build_graph(const std::unordered_set<std::string>& words)
{
    std::unordered_map<std::string, std::vector<std::string>> graph;
    for (const std::string& word1 : words)
    {
        for (const std::string& word2 : words)
        {
            if (one_letter_diff(word1, word2))
            {
                graph[word1].push_back(word2);
            }
        }
    }
    return graph;
}

std::vector<std::string> bfs(const std::string& start, const std::string& end, const std::unordered_map<std::string, std::vector<std::string>>& graph)
{
    std::unordered_set<std::string> visited;
    std::queue<std::pair<std::string, std::vector<std::string>>> q;

    q.push({start, {start}});
    visited.insert(start);

    while (!q.empty())
    {
        auto [current, path] = q.front();
        q.pop();

        if (current == end) return path;

        auto it = graph.find(current);
        if (it != graph.end())
        {
            for (const std::string& neighbor : it->second)
            {
                if (!visited.count(neighbor))
                {
                    visited.insert(neighbor);
                    std::vector<std::string> new_path = path;
                    new_path.push_back(neighbor);
                    q.push({neighbor, new_path});
                }
            }
        }
    }

    return {};
}

int main()
{
    std::unordered_set<std::string> word_set = load_words("words.txt");

    std::string start = "ster";
    std::string end = "atom";

    if (word_set.find(start) == word_set.end() || word_set.find(end) == word_set.end())
    {
        std::cout << "Start or end word not found in dictionary." << std::endl;
        return 1;
    }

    std::unordered_map<std::string, std::vector<std::string>> graph = build_graph(word_set);

    std::vector<std::string> path = bfs(start, end, graph);

    if (!path.empty())
    {
        std::cout << "Shortest path from \"" << start << "\" to \"" << end << "\":" << std::endl;
        for (const std::string& word : path)
        {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No path found." << std::endl;
    }

    return 0;
}