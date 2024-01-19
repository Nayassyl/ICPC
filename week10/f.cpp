#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

#define MAX 2001

#define INF 0x3F3F3F3F

int g[MAX][MAX], used[MAX], dist[MAX];
void Relax(int i, int j)

{

  if (dist[i] + g[i][j] < dist[j])

    dist[j] = dist[i] + g[i][j];

}
int main(){
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
    int n, s, f, i , j, min , v;
    scanf("%d %d %d",&n,&s,&f);
    memset(g,0x3F,sizeof(g));

memset(used,0,sizeof(used));

memset(dist,0x3F,sizeof(dist));

dist[s] = 0;
for(i = 1; i <= n; i++)
    for(j = 1; j <= n; j++)
        scanf("%d",&g[i][j]);

for(i = 1; i < n; i++)

{

  min = INF; v = -1;

  for(j = 1; j <= n; j++)

    if (used[j] == 0 && dist[j] < min) {min = dist[j]; v = j;}
    if (v < 0) break;
    for(j = 1; j <= n; j++)

    if (used[j] == 0 && g[v][j] != -1) Relax(v,j);

used[v] = 1;

}

 if (dist[f] == INF) printf("-1\n");

else printf("%d\n",dist[f]);

}