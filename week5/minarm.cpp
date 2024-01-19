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
#define inf 1e18
using namespace std;
class segment_tree
{
public:
    vector<int> tree;
    int size;
    segment_tree(vector<int> &arr)
    {
        size = 4 * arr.size();
        tree.resize(size);
        build(arr, 0, 0, arr.size() - 1);
    }

private:
    void build(vector<int> &arr, int index, int left, int right)
    {
        if (left == right)
        {
            tree[index] = arr[left];
            return;
        }
        int mid = (right + left) / 2;
        build(arr, 2 * index + 1, left, mid);
        build(arr, 2 * index + 2, mid + 1, right);
        tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
    }
    int query(int index, int left, int right, int queryleft, int queryright)
    {
        if (right < queryleft || left > queryright)
            return 1e9;
        if (queryleft <= left && right <= queryright)
            return tree[index];
        int mid = (right + left) / 2;
        return min(query(2 * index + 1, left, mid, queryleft, queryright), query(2 * index + 2, mid + 1, right, queryleft, queryright));
    }

public:
    int query(int left, int right)
    {
        return query(0, 0, size / 4 - 1, left, right);
    }
};
int main()
{
    int n, k, l, r;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    segment_tree st = segment_tree(v);
    while (k--)
    {
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << '\n';
    }
}