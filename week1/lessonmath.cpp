#include <iostream>
#include <cmath>
using namespace std;
void prime_product(int n){
    if (n <= 1) cout << n;
    for(int i = 2; i <= sqrt(n); i++){
        int cnt = 0; 
        if ( n % i != 0) continue;
        while ( n % i == 0){
            n /= i;
            cnt++;
        }
        if( cnt > 1){
            cout << i << '^' << cnt;
        }else cout << i;
        if ( n > 1 ) cout << '*';
    }
    if (n > 1) cout << n << endl;
}
int main(){
    int n; cin >> n;
    prime_product(n);
}
