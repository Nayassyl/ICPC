#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 2000000000
using namespace std;
#define MAX 1010
int a[MAX][MAX], dp[MAX][MAX];
int main(){
    int n, m, i, j;
    vector<pair<int, int>> path; 
    cin >> n >> m; 
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for (i = 2; i <= n; i++)
        dp[i][1] = dp[i - 1][1] + a[i][1];
    for (j = 2; j <= m; j++)
        dp[1][j] = dp[1][j - 1] + a[1][j];
    
    for (i = 2; i <= n; i++)
        for (j = 2; j <= m; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];

    cout << dp[n][m];

    i = n; j = m;
    while (i > 1 && j > 1){
        path.push_back(make_pair(i, j));
        if (dp[i - 1][j] + a[i][j] == dp[i][j]) i--; else j--;
    }
    while (i > 1) path.push_back(make_pair(i, j)), i--;
    while (j > 1) path.push_back(make_pair(i, j)), j--;
    path.push_back(make_pair(1, 1));
    reverse(path.begin(), path.end());
    for (i = 0; i < path.size(); i++)
        cout << "\n" <<path[i].first << " " << path[i].second << "\n";

}