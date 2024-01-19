#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
int irred(int n){
    int cnt = 0, res = n; 
    for(int i = 2; i * i <= n; i++){
        if( n % i == 0 ) res -= res / i;
        while( n % i == 0) n /= i;
    }
    if( n > 1 ) res -= res / n;
    return res;
}
int main()
{
    int a;
    cin >> a;
    while(a != 0){
        cout << irred(a) << endl;
        cin >> a;
    }
}