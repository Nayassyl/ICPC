#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <sstream>
#include <numeric>
#include <bitset>
#define str string
#define ll long long
#define mod 1000000007
using namespace std;
class segment_tree
{
public:
    vector<ll> tree;
    int size;
    segment_tree(vector<ll> &arr)
    {
        size = 4 * arr.size();
        tree.resize(size);
        build(arr, 0, 0, size - 1);
    }

private:
    void build(vector<ll> &arr, int index, int left, int right)
    {
        if (left == right)
        {
            tree[index] = arr[left];
            return;
        }
        int mid = (right + left) / 2;
        build(arr, 2 * index + 1, left, mid);
        build(arr, 2 * index + 2, mid + 1, right);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
    ll sum(int index, int left, int right, int queryleft, int queryright)
    {
        if (right < queryleft || left > queryright)
            return 0LL;
        if (queryleft <= left && right <= queryright)
            return tree[index];
        int mid = (left + right) / 2;
        return sum(2 * index + 1, left, mid, queryleft, queryright) + sum(2 * index + 2, mid + 1, right, queryleft, queryright);
    }

public:
    ll query(int left, int right)
    {
        return sum(0, 0, size - 1, left, right);
    }
};
int main()
{
    int n, t, l, r;
    cin >> n >> t;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    segment_tree st = segment_tree(v);
    for (int i = 0; i < st.size; ++i)
        cout << st.tree[i] << ' ';
    // while (t--)
    // {
    //     cin >> l >> r;
    //     cout << st.query(l - 1, r - 1) << '\n';
    // }
}