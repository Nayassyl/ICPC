#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

void dfs1(int v, std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::stack<int>& finishStack) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u, graph, visited, finishStack);
        }
    }
    finishStack.push(v);
}

void dfs2(int v, std::vector<std::vector<int>>& transposeGraph, std::vector<bool>& visited, std::vector<int>& component, int id) {
    visited[v] = true;
    component[v] = id;
    for (int u : transposeGraph[v]) {
        if (!visited[u]) {
            dfs2(u, transposeGraph, visited, component, id);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n), transposeGraph(n);
    std::vector<bool> visited(n, false);
    std::stack<int> finishStack;
    std::vector<int> component(n, -1); // To store the component id of each node

    // Reading the graph
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u; --v; // Adjusting for 0-based indexing
        graph[u].push_back(v);
        transposeGraph[v].push_back(u);
    }

    // First DFS pass to fill the finishStack
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, graph, visited, finishStack);
        }
    }

    // Prepare for the second DFS pass
    std::fill(visited.begin(), visited.end(), false);
    int id = 0;

    // Second DFS pass to find SCCs
    while (!finishStack.empty()) {
        int v = finishStack.top();
        finishStack.pop();
        if (!visited[v]) {
            dfs2(v, transposeGraph, visited, component, id++);
        }
    }

    // Creating the condensation graph
    std::vector<int> outDegree(id, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            if (component[u] != component[v]) {
                outDegree[component[u]]++;
            }
        }
    }

    // Counting sink components
    int sinks = 0;
    for (int i = 0; i < id; ++i) {
        if (outDegree[i] == 0) {
            sinks++;
        }
    }

    // Output the results
    std::cout << sinks << std::endl;
    for (int i = 0; i < n; ++i) {
        if (outDegree[component[i]] == 0) {
            std::cout << i + 1 << " "; // Print houses for fire stations (1-indexed)
            outDegree[component[i]] = -1; // Ensure each component is printed only once
        }
    }

    return 0;
}
