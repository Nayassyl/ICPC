#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;

#define ll long long

pair<int, int> t[2 * (int)pow(2, ceil(log2(100000))) - 1];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    return make_pair(max(a.first, b.first), min(a.second, b.second));
}

void build(int a[], int n) {
    for (int i = 0; i < n; i++) {
        t[i + n] = make_pair(a[i], a[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        t[i] = combine(t[i * 2], t[i * 2 + 1]);
    }
}

void update(int pos, int data, int n) {
    t[pos + n] = make_pair(data, data);
    for (int i = (pos + n) / 2; i > 0; i /= 2) {
        t[i] = combine(t[i * 2], t[i * 2 + 1]);
    }
}

pair<int, int> query(int l, int r, int n) {
    pair<int, int> result = make_pair(-1e9, 1e9);
    for (l += n, r += n; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) {
            result = combine(result, t[l]);
            l++;
        }
        if (r % 2 == 0) {
            result = combine(result, t[r]);
            r--;
        }
    }
    return result;
}

int main() {
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);
    int a[100000];
    for (int i = 0; i < 100000; i++) {
        a[i] = (i % 12345 * i % 12345) % 12345 + (i % 23456 * i % 23456 * i % 23456) % 23456;
    }
    
    int n = 100000;
    build(a, n);
    
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        // auto start = chrono::high_resolution_clock::now();
        
        if (x > 0) {
            pair<int, int> result = query(x, y, n);
            cout << result.first - result.second << '\n';
        } else {
            update(abs(x), y, n);
        }
        
    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }
    
    return 0;
}