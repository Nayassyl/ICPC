#include <iostream>
#include <algorithm>
using namespace std; 
int main(){
    // freopen("slalom.in", "r", stdin);
    // freopen("slalom.out", "w", stdout);
    int n; cin >> n; 
    int arr[n][n];
    int dp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][0] = dp[i-1][0] + arr[i][0];
            else if(i == j) dp[i][i] = dp[i-1][i - 1] + arr[i][i];
            else{
                dp[i][j] = max(dp[i - 1][j - 1], dp[i-1][j]) + arr[i][j];}
        }
    }
    int maxx = -1000000000;
    for(int i = 0; i < n; i++){
        if(dp[n - 1][i] > maxx) maxx = dp[n-1][i];
    }
    cout << maxx;
}
