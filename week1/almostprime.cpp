#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001
int primes[MAX];
long long m[MAX];
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
    long long ptr;
    for(int i = 2; i <= MAX; i++){
        if(primes[i]){
            long long temp = 1LL*i*i;
            while(temp < 1LL*MAX*MAX){ 
                m[ptr++] = temp;
                temp *= i;
            }
        }
    }
    sort(m, m + ptr);
    int t;
    cin >> t;
    long long a, b;
    //cin >> a >> b;
    while(t--){
        cin >> a >> b;
        int cnt = 0;
        for(long long i = 0; i <= ptr; i++){
            if (m[i] >= a and m[i] <= b) cnt++;
        }
        cout << cnt << endl;
    }
}