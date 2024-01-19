#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
pair<int, int> t[8];
void build(int a[], int index, int left, int right)
{
    if (left == right)
    {
        t[index] = make_pair(a[left], a[left]);
    }
    else
    {
        int m = (left + right) / 2;
        build(a, 2 * index, left, m);
        build(a, 2 * index + 1, m + 1, right);
        t[index] = make_pair(max(t[2 * index].first, t[2 * index + 1].first), min(t[2 * index + 1].second, t[2 * index].second));
    }
}
int main()
{
    int a[5];
    for(int i = 1; i <= 4; i++){
        a[i] = i*i % 12345 + i*i*i % 23456;
    }
    build(a, 1, 1, 4);
    for(int i = 0; i <= 16; i++) cout << t[i].first << " " << t[i].second << "\n";
}
// 2 12 36 80 150 252 392 576 810 1100 1452 1872 2366 2940 3600 4352 5202 6156 7220 8400