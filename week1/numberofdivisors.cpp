#include <iostream>
#include <cmath>
using namespace std;
int number_of_divisors(int n){
    int cnt = 0;
    int div = 1;
    for(int i = 2; i <= sqrt(n); i++){
        if( n % i == 0){
            while(n % i == 0){
                n /= i;
                cnt++;
            }
            div *= (cnt + 1);
            cnt = 0;
        }
    }
    if (n > 1)  return div * 2 - 2;
    return div - 2;
}
int main(){
    int n; cin >> n;
    cout << number_of_divisors(n);
}