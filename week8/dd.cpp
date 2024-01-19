#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<vector<int>> g;
vector<int> used, d, f, parent;
int current_time = 1; // Start time from 1

void dfs(int v) {
    used[v] = 1;
    d[v] = current_time++; // Update discovery time
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            parent[to] = v; // Update parent
            dfs(to);
        }
    }
    f[v] = current_time++; // Update finish time
}

int is_Parent(int a, int b) {
    return (d[a] <= d[b]) && (f[b] <= f[a]);
}

int main() {
    int n, m, a, b, root = 1;
    scanf("%d", &n);
    g.resize(n+1); 
    used.resize(n+1, 0);
    d.resize(n+1); 
    f.resize(n+1);
    parent.resize(n+1, -1);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(a != 0) {
            g[a].push_back(i);
            g[i].push_back(a);
        }
    }

    dfs(root); // Perform DFS from the root

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", is_Parent(a, b) ? a : (is_Parent(b, a) ? b : 0));
    }

    return 0;
}
