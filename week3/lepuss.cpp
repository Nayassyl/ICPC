#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    // freopen("lepus.in", "r", stdin);
    // freopen("lepus.out", "w", stdout);
    int n;
    cin >> n;
    char b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int arr[n];
    for(int i = 0; i < n; i++){
        if(b[i] == '"') arr[i] = 1;
        else if ( b[i] == '.') arr[i] = 0;
        else arr[i] = -1;
    }
    int dp[n];
    dp[0] = arr[0];
    dp[1] = arr[1];
    
    
    if(dp[1] == -1 or arr[2] == -1) dp[2] = -1;
    else dp[2] = dp[1] + arr[2];

    if(arr[3] == -1 or max(dp[2], dp[0]) == -1) dp[3] = -1;
    else dp[3] = max(dp[0], dp[2]) + arr[3];

    if (arr[4] == -1 or max(dp[1], dp[3]) == -1) dp[4] = -1;
    else dp[4] = max(dp[1], dp[3]) + arr[4];

    if(arr[5] == -1) dp[5] = -1;
    else dp[5] = max(max(dp[0], dp[2]), dp[4]) + arr[5];

    for (int i = 6; i < n; i++)
        if( max(arr[i], arr[i-1]) == -1 and max(arr[i-3], arr[i-6]) == -1)
            dp[i] = -1;
        else dp[i] = max(max(dp[i - 1], dp[i - 3]), dp[i - 5]) + arr[i];
    for(int i = 0; i < n; i++) cout << dp[i];
}