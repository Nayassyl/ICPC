#include <iostream>
using namespace std;
#define MAX 10000001
int primes[MAX];
void gen_primes(void){
    int i, j;
    for (i = 0; i < MAX; i++) primes[i] = 1;
    primes[0] = primes[1] = 0;
    for (i = 2; i * i <= MAX; i++){
        if (primes[i]){
            for (j = i * i; j < MAX; j += i) primes[j] = 0;
        }
    }
}
int main(){
    gen_primes();
    int a, b;
    //cin >> a >> b;
    while(cin >> a >> b){
        int cnt = 0;
        for(int i = a; i <= b; i++){
            if(primes[i]) cnt++;
        }
        cout << cnt << endl;
        cout << endl;
    }
}
