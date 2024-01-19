#include <iostream>
#include <vector>
#include <stack>

bool dfs(int v, std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<bool>& recStack, std::stack<int>& topologicalOrder) {
    visited[v] = true;
    recStack[v] = true;

    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack, topologicalOrder)) return true;
        } else if (recStack[neighbor]) {
            // A cycle is detected
            return true;
        }
    }

    topologicalOrder.push(v);
    recStack[v] = false;
    return false;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    std::vector<bool> visited(n, false), recStack(n, false);
    std::stack<int> topologicalOrder;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u - 1].push_back(v - 1); // Assuming 1-based indexing of vertices
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack, topologicalOrder)) {
                std::cout << -1 << std::endl; // Cycle detected, so topological sorting is not possible
                return 0;
            }
        }
    }

    while (!topologicalOrder.empty()) {
        std::cout << topologicalOrder.top() + 1 << " "; // Print vertices in topological order
        topologicalOrder.pop();
    }

    return 0;
}
