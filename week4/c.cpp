#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("success.in", "r", stdin);
    freopen("success.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    next_permutation(arr, arr + n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}