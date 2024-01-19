#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll dist(int a, int b){
    
}
int main(){
    int a, b;
    cin >> a >> b; 
    ll ans = 0;
    while(b >= 1){
        ans += dist(a, b);
        b--;
    }
    cout << ans;
    
}