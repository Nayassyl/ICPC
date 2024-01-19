#include <iostream>
#include <vector>

void DFS(int vertex, std::vector<bool>& visited, const std::vector<std::vector<int>>& graph) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited, graph);
        }
    }
}

bool isConnected(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<bool> visited(n, false);

    // Perform DFS from vertex 0 (or any vertex)
    DFS(0, visited, graph);

    // Check if all vertices are visited
    for (bool v : visited) {
        if (!v) {
            return false;  // If any vertex is not visited, graph is not connected
        }
    }

    return true;  // All vertices are visited, so graph is connected
}

int main() {
    // Example usage:
    // Number of vertices
    int n, m;
    std::cin >> n >> m;

    // Adjacency list of the graph
    std::vector<std::vector<int>> graph(n);
    // Read the edges and construct the graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // Since the graph is undirected
    }

    // Check if the graph is connected
    if (isConnected(graph)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
