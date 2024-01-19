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
class node
{
public:
    int maximum;
    int minimum;
    node()
    {
        maximum = minimum = 0;
    }
    node(int _max, int _min)
    {
        this->maximum = _max;
        this->minimum = _min;
    }
};
class segment_tree
{
public:
    vector<node> tree;
    int size;
    segment_tree(vector<int> &arr)
    {
        size = arr.size() * 4;
        tree.resize(size);
        build(arr, 0, 0, arr.size() - 1);
    }

private:
    void build(vector<int> &arr, int index, int left, int right)
    {
        if (right == left)
        {
            tree[index] = node(arr[left], arr[right]);
            return;
        }
        int mid = (right + left) / 2;
        build(arr, 2 * index + 1, left, mid);
        build(arr, 2 * index + 2, mid + 1, right);
        tree[index] = node(max(tree[index * 2 + 1].maximum, tree[index * 2 + 2].maximum),
                           min(tree[index * 2 + 1].minimum, tree[index * 2 + 2].minimum));
    }
    void update(int index, int left, int right, int position, int value)
    {
        if (right == left)
        {
            tree[index] = node(value, value);
            return;
        }
        int mid = (left + right) / 2;
        if (position <= mid)
            update(2 * index + 1, left, mid, position, value);
        else
            update(2 * index + 2, mid + 1, right, position, value);
        tree[index] = node(max(tree[index * 2 + 1].maximum, tree[index * 2 + 2].maximum),
                           min(tree[index * 2 + 1].minimum, tree[index * 2 + 2].minimum));
    }
    node query(int index, int left, int right, int queryleft, int queryright)
    {
        if (right < queryleft || left > queryright)
            return node(-1e9, 1e9);
        if (queryleft <= left && right <= queryright)
            return tree[index];
        int mid = (left + right) / 2;
        node leftchild = query(2 * index + 1, left, mid, queryleft, queryright);
        node rightchild = query(2 * index + 2, mid + 1, right, queryleft, queryright);
        return node(max(leftchild.maximum, rightchild.maximum),
                    min(leftchild.minimum, rightchild.minimum));
    }

public:
    void update(int position, int value)
    {
        update(0, 0, size / 4 - 1, position, value);
    }
    int query(int left, int right)
    {
        node result = query(0, 0, size / 4 - 1, left, right);
        return result.maximum - result.minimum;
    }
};
int main()
{
    const int N = 1e5 + 1;
    int t, x, y;
    cin >> t;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        v[i] = (((i + 1) % 12345) * ((i + 1) % 12345)) % 12345 + (((i + 1) % 23456) * ((i + 1) % 23456) * ((i + 1) % 23456)) % 23456;
    segment_tree st = segment_tree(v);
    while (t--)
    {
        cin >> x >> y;
        if (x > 0)
            cout << st.query(x - 1, y - 1) << '\n';
        else
        {
            x = abs(x);
            st.update(x - 1, y);
        }
    }
}