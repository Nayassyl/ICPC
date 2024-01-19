#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // Бесконечность

int main()
{
    freopen("sumdist.in", "r", stdin);
    freopen("sumdist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;                         // Переход к 0-индексации
        dist[u][v] = dist[v][u] = 1; // Расстояние между соседними вершинами равно 1
    }

    // Алгоритм Флойда-Уоршелла
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Суммирование расстояний
    long long total_distance = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            total_distance += dist[i][j];
        }
    }

    cout << total_distance / 2 << endl;
    return 0;
}
