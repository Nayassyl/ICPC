#include <iostream>
#include <cmath>
using namespace std;
void sums(int sum){
    for( int i = 2; i <= sqrt(sum * 2); i++){
        if( (sum * 2) % i == 0 ){
            int a1 = (2 * sum)/ i - i + 1;
            if (a1 % 2 == 0 and a1 > 0){
                int first_elem = a1 / 2;
                cout << sum << " = " << first_elem;
                for( int j = 1; j < i; j++){
                    cout << " + " << first_elem + j;
                }
                return;
            }
        }
    }cout << "IMPOSSIBLE";
}
int main(){
    int n; cin >> n;
    while(n--){
        int sum; cin >> sum;
    sums(sum);
    cout << endl;
    }
}