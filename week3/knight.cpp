#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    int n, m, max = 55;
    cin >> n >> m;
    int dp[max][max];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= m; ++j)
            dp[i][j] = dp[i - 1][j - 2] + dp[i - 2][j - 1];
    }
    cout << dp[n][m];
    
}