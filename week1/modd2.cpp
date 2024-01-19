#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ull;
ull a, b, c, res;
ull mult(ull a, ull  b, ull c){
    if (b == 0) return 0;
    if (b % 2 == 0) return mult((2 * a) % c, b / 2, c);
    return (mult(a, b - 1, c) + a) % c;
}
ull pow(ull a, ull b, ull c){
    ull temp;
    if (b == 0) return 1;
    temp = pow(a,b/2,c);
    if (b % 2 == 0) return mult(temp,temp,c);
    else return mult(mult(temp,temp,c),a,c);
}
int main(){
    while(cin >> a >> b >> c){
        a = a % c;
        if (a == 1) res = 1; else res = pow(a,b,c);
        cout << res;
    }
    return 0;
}
