#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
ll pow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 0)
        return pow(a * a, b / 2);
    return a * pow(a * a, b / 2);
}
int main()
{
    ll x, n;
    cin >> x >> n;
    cout << pow(x, n);
}