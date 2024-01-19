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
    vector<ll> tree;
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
        tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
    }
    void update(int index, int left, int right,int data, int X){
	if (tree[left] == data && tree[right] == data){
		tree[right] -= X;
	}
	else{
		int mid = (left + right) / 2;
		if(data <= tree[mid])
			update(2 * index, left, mid,data, X);
		else
			update(2 * index + 1, mid + 1, right, data, X);
		tree[index] = max(tree[index * 2 + 1], tree[2 * index + 2]);
	}
}

public:
    void update(int data, int X)
    {
        return update(0, 0, size / 4 - 1, data, X);
    }
    int get(int index){
        return tree[index];
    }
};
int main()
{
    int n, X;
    cin >> n >> X;
    vector<int> v(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    segment_tree st = segment_tree(v);
    int maxx = st.get(1);
    int cnt = 0;
    // while(maxx > 0)
    // {
    //     st.update(maxx, X);
    //     cnt++; 
    //     X = (X + 1) / 2;
    //     maxx = st.get(1);
    // }
    // cout << cnt; 
    for(int i = 0; i < 28; i++) cout << st.get(i) << " ";
}
