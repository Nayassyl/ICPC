#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;
#define ll long long
pair<int, int> t[2 * (int)pow(2,ceil(log2(100000)) ) -1];

pair<int, int> combine(pair<int, int> a, pair<int, int> b){
    return make_pair(max(a.first, b.first), min(a.second, b.second));
}
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
        t[index] = combine(t[index * 2], t[index * 2 + 1]);
    }
}
void update(int index, int left, int right, int pos, int data){
    if (left == right){
        t[index] = make_pair(data, data);
    }
    else{
        int mid = (left + right) / 2;
        if(pos <= mid)
            update(2 * index, left, mid, pos, data);
        else
            update(2 * index + 1, mid + 1, right, pos, data);
        t[index] = combine(t[index * 2], t[index * 2 + 1]);
    }
}
pair<int, int> query(int index, int left, int right , int queryleft, int queryright) {  
    if (queryleft > queryright)
        return make_pair(-1e9, +1e9);
    if (queryleft == left && right == queryright)
        return t[index];
    int mid = (left + right) / 2;
    pair<int, int> firstchild = query(index * 2, left, mid, queryleft, min(queryright, mid));
    pair<int, int> secondchild = query(index * 2 + 1, mid + 1, right, max(queryleft, mid + 1), queryright);
    return combine(firstchild, secondchild);
}
void query(int left,int right){
    pair<int,int> ans = query(1,1,100000,left,right);
    cout << ans.first - ans.second<<'\n';
}
int main()
{
    // freopen("rvq.in", "r", stdin);
    // freopen("rvq.out", "w", stdout);
    int a[100001];
    for(int i = 1; i <= 100000; i++){
        a[i] = (i % 12345 * i % 12345) % 12345 + (i % 23456 * i % 23456 * i % 23456) % 23456;
    }
    build(a, 1, 1, 100000);
    int q; cin >> q;
    while(q--){
        int x, y; 
        cin >> x >> y; 
        auto start = chrono::high_resolution_clock::now();
        if( x > 0 )
            query(x,y);
        else
            update(1, 1, 100000, abs(x), y);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }
}