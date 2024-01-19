#include <iostream>
#include <algorithm>
using namespace std; 
int main(){
    int i;
    int n = 4; 
    int a[4]; 
    int nn[4]; 
    for(i = 0; i < n; i++) cin >> a[i];
    for(i = 0; i < n; i++) cin >> nn[i];
    sort(a, a + 4);
    sort(nn, nn + 4);
    int sum1 = a[1] + a[2] + a[3];
    int sum2 = nn[1] + nn[2] + nn[3];
    if (sum1 > sum2) cout << "aibark";
    else if(sum2 > sum1) cout << "Na2a";
    else cout << "Tekor";
}
