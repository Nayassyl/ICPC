#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);
    int n;
    cin >> n;
    int b[n];
    for (int i = 1; i <= n; i++)
        b[i - 1] = i;
    do
    {
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << '\n';
    } while (next_permutation(b, b + n));
}