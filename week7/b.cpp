#include <iostream>
#include <vector>

void DFS(int vertex, int parent, const std::vector<std::vector<int>>& graph, std::vector<std::pair<int, int>>& treeEdges, std::vector<bool>& visited) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            treeEdges.push_back({vertex, neighbor});  // Record the edge
            DFS(neighbor, vertex, graph, treeEdges, visited);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;  // Read the number of vertices (n) and edges (m)

    std::vector<std::vector<int>> graph(n);
    std::vector<bool> visited(n, false);
    std::vector<std::pair<int, int>> treeEdges;  // To store the edges of the tree

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;  // Read the edges
        --u; --v;  // Adjusting for 0-based indexing if needed
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Perform DFS to find the tree edges
    DFS(0, -1, graph, treeEdges, visited);

    // Output the tree edges
    for (const auto& edge : treeEdges) {
        std::cout << edge.first + 1 << " " << edge.second + 1 << std::endl;  // Adjusting back to 1-based indexing if needed
    }

    return 0;
}
