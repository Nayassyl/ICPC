#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void buildTree(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(data, 2 * node + 1, start, mid);
            buildTree(data, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void updateTree(int node, int start, int end,int X, int val) {
        if (start == end) {
            tree[node] -= X;
        } else {
            int mid = (start + end) / 2;
            if (tree[start] <= val && val <= tree[mid]) {
                updateTree(2 * node + 1, start, mid, X, val);
            } else {
                updateTree(2 * node + 2, mid + 1, end, X, val);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int queryMax(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return numeric_limits<int>::min();
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = queryMax(2 * node + 1, start, mid, l, r);
        int rightMax = queryMax(2 * node + 2, mid + 1, end, l, r);
        return max(leftMax, rightMax);
    }

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        buildTree(data, 0, 0, n - 1);
    }

    void update(int X, int val) {
        updateTree(0, 0, n - 1, X, val);
    }

    int queryMax(int l, int r) {
        return queryMax(0, 0, n - 1, l, r);
    }
    int get(int ind){
        return tree[ind];
    }
};

int main() {
    int n, X; 
    cin >> n >> X;
    vector<int> data(n); 
    for(int i = 0; i < n; i++){ cin >> data[i];}
    SegmentTree st(data);
    int maxx = st.get(0); 
    
}
