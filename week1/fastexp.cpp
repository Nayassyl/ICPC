#include <iostream>
#include <cmath>
#define ll long long
#define str string
using namespace std;
str fast_exp(int n){
    int r;
    str res = "";
    while(n != 0){
        r = n % 2;
        if(r){
            if (n != 1) res = "SX" + res;
        }
        else res = "S" + res;
        n /= 2;
    }
    return res;
}
int main()
{
    int n; cin >> n;
    cout << fast_exp(n);
}