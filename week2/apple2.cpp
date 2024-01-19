#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007
int dist(int n, int m){
    int res = 1;
    if(n - 1 >= m){
        for( int i = n; i <= m + n - 1 ;i++) res *= i, res %= mod;
        for(int i = 1; i  <= m; i++) res /= i;
    }else{
        for(int i = m + 1; i <= m + n - 1; i++) res *= i, res %= mod;
        for (int i = 1; i <= n - 1; i++) res /= i;
    }
    return res % mod;

}
int main(){
    int n, m;
    cin >> n >> m; 
    cout << dist(n, m);
}