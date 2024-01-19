#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    ll dp[n + 1];
    dp[0] = -10000000;
    dp[1] = arr[0];
    if( n > 1 )
        dp[2] = arr[1] + ((dp[1] >= 0) ? dp[1] : 0);
    for (int i = 3; i <= n; ++i)
        dp[i] = max(dp[i - 1], dp[i - 2]) + arr[i - 1];
    cout << dp[n];
}