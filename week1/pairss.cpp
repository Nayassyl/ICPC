#include <iostream>
#include <cmath>
using namespace std;
int pair_num(int n){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += n / i;
    }
    return cnt;
}
int main(){
    int n; cin >> n;
    cout << pair_num(n);
}