#include <iostream>
#include <algorithm>
using namespace std; 

#define MAX 101
int a[MAX], dp[MAX];
int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    dp[2] = a[2] - a[1];
    dp[3] = a[3] - a[1];
    for(int i = 4; i <= n; i++)
        dp[i] = min(dp[i-1],dp[i-2]) + a[i] - a[i-1];

    cout << dp[n];
}