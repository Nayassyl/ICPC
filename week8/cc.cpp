#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
vector<vector<int> > g;

vector<int> used, d, f;
int time;
void dfs(int v)

{

  used[v] = 1; d[v] = time++;

  for(int i = 0; i < g[v].size(); i++)

  {

    int to = g[v][i];

    if (!used[to]) dfs(to);

  }

  f[v] = time++;

}
 

int is_Parent(int a, int b)

{

  return (d[a] < d[b]) && (f[b] < f[a]);

}
scanf("%d",&n);

g.resize(n+1); used.resize(n+1);

d.resize(n+1); f.resize(n+1);

for(i = 1; i <= n; i++)

{

  scanf("%d",&a);

  if(!a) root = i; else g[a].push_back(i);

}

dfs(root);

 scanf("%d",&m);

for(i = 0; i < m; i++)

{

  scanf("%d %d",&a,&b);

  printf("%d\n",is_Parent(a,b));

}