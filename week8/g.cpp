#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<pair<int, int>>> g;

vector<long long> dist;
void dfs(int v, int p = -1)

{
    for (auto x : g[v])

    {
        int to = x.first;

        int w = x.second;
        if (to != p)

        {

            dist[to] = dist[v] + w;

            dfs(to, v);
        }
    }
}
int main(){
int n, b, e, w, i;
scanf("%d", &n);

g.resize(n + 1);

for (i = 0; i < n - 1; i++)

{

    scanf("%d %d %d", &b, &e, &w);

    g[b].push_back({e, w});

    g[e].push_back({b, w});
}
dist.assign(n + 1, -1);

dist[1] = 0;

dfs(1);
int v = max_element(dist.begin(), dist.end()) - dist.begin();

dist.assign(n + 1, -1);

dist[v] = 0;

dfs(v);
v = max_element(dist.begin(), dist.end()) - dist.begin();
printf("%lld\n", dist[v]);
}