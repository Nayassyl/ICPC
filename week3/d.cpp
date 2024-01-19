#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
    int arr[8][8], dp[9][9];
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            cin >> arr[i][j];
    }
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
            dp[i][j] = 10000000;
    }
    dp[8][0] = 0;
    for (int i = 7; i >= 0; --i)
    {
        for (int j = 1; j <= 8; ++j)
            dp[i][j] = arr[i][j - 1] + min(min(dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1]);
    }
    cout << dp[0][8];
}