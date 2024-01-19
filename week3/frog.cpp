#include <iostream>
#include <cmath>
#include <cstring>
#define str string
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n], dp[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < n; i++)
        dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
    cout << dp[n - 1];
}