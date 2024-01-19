#include <iostream>
#include <vector>

bool dfs(int v, int parent, std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            if (dfs(u, v, graph, visited)) return true; // Найден цикл
        } else if (u != parent) {
            return true; // Найден цикл
        }
    }
    return false;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n);
    std::vector<bool> visited(n, false);
    int edges = 0;

    // Чтение матрицы смежности и подсчет ребер
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int edge;
            std::cin >> edge;
            if (edge) {
                if (i < j) edges++; // Избежать подсчета одного и того же ребра дважды
                graph[i].push_back(j);
            }
        }
    }

    // Проверка на количество рёбер
    if (edges != n - 1) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    // Проверка на связность и наличие циклов
    if (!dfs(0, -1, graph, visited) && std::all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
