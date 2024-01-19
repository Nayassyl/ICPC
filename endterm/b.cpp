#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, res(0); cin >> n; 
    for(int i = 1; i < n; ++i) res += (n - 1) / i; 
    cout << res;
}