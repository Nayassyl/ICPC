#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    // freopen("inverse.in", "r", stdin);
    // freopen("inverse.out", "w", stdout);
    int n;
     cin >> n;
    int a1[n], a2[n];
    for(int i = 0; i < n; i++){
        cin >> a1[i]; a2[a1[i] - 1] = i + 1;
    }
    for(int i = 0; i < n ; i++)
        cout << a2[i] << " ";
}