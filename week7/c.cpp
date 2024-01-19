#include <iostream>
#include <vector>

bool dfs(int vertex, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<bool>& recStack) {
    if(!visited[vertex]) {
        visited[vertex] = true;
        recStack[vertex] = true;  // Mark the vertex as part of the current path

        for(int neighbor = 0; neighbor < graph[vertex].size(); ++neighbor) {
            if(graph[vertex][neighbor] != 0 && !visited[neighbor] && dfs(neighbor, graph, visited, recStack))
                return true;  // Cycle found
            else if(graph[vertex][neighbor] != 0 && recStack[neighbor])
                return true;  // Cycle found
        }
    }
    recStack[vertex] = false;  // Remove the vertex from the current path
    return false;
}

bool isCyclic(const std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false);
    std::vector<bool> recStack(graph.size(), false);

    for(int i = 0; i < graph.size(); ++i) {
        if(dfs(i, graph, visited, recStack)) {
            return true;  // Cycle found
        }
    }
    return false;  // No cycles found
}

int main() {
    int n;
    std::cin >> n;  // Number of vertices

    std::vector<std::vector<int>> graph(n, std::vector<int>(n));

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];  // Reading the adjacency matrix
        }
    }

    std::cout << isCyclic(graph) << std::endl;  // Print "1" if cyclic, "0" otherwise

    return 0;
}
