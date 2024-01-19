#include <iostream>
#include <queue>
#include <iomanip> 
using namespace std;


vector<vector<int> > g;
vector<int> dist;
 
 
void find(int start)
{
  queue<int> q;
  q.push(start);
  while (!q.empty())
  {
    int v = q.front(); q.pop();
    for (int i = 0; i < g[v].size(); i++)
    {
      int to = g[v][i];
      if (dist[to] == -1)
      {
        q.push(to);
        dist[to] = dist[v] + 1;
      }
    }
  }
}

int main(){
    
    int n,m,s,d;
    scanf("%d %d %d %d", &n, &m, &s, &d);
    g.resize(2*n + 1);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        
        
        g[2*u].push_back(2*v-1);
        g[2*v-1].push_back(2*u);
        g[2*v].push_back(2*u-1);
        g[2*u-1].push_back(2*v);
    }
    
    
    n = 2 * n;
    
    
    dist = vector<int>(n + 1, -1);
    dist[2*s-1] = 0;
    
    
    find(2*s-1);
    
    
    printf("%d\n", dist[2*d-1]);
}