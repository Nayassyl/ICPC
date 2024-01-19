#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("generation.in", "r", stdin);
    freopen("generation.out", "w", stdout);
    int n, r;
    cin >> n;
    cin >> r;

    vector<bool> v(n);
    fill(v.end() - r, v.end(), true);

    do
    {
        for (int i = n -1 ; i >= 0; i--)
        {
            if (v[i])
            {
                cout << (i + 1) << " ";
            }
        }
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}