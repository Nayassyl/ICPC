#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<vector<int>> g;
vector<int> used, d, f;
int tt = 0;

void dfs(int v) {
    used[v] = 1;
    d[v] = tt++;
    for(int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) dfs(to);
    }
    f[v] = tt++;
}

int is_Parent(int a, int b) {
    return (d[a] < d[b]) && (f[b] < f[a]);
}

int main() {
    int n, m, a, b, root;
    scanf("%d", &n);
    g.resize(n+1); 
    used.resize(n+1);
    d.resize(n+1); 
    f.resize(n+1);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(!a) root = i; else g[a].push_back(i);
    }

    dfs(root);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", is_Parent(a, b));
    }

    return 0;
}
