#include <iostream>
using namespace std;
#define ll long long 
ll t[800000];
void build(int a[], int v, int l, int r){
	if(l == r){
		t[v] = a[l];
	}
	else{
		int m = (l + r)/2;
		build(a, 2*v,  l, m);
		build(a, 2*v + 1, m+1, r);
		t[v] = t[2*v] + t[2*v + 1];
	}
}
ll sum (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0LL;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return sum (v*2, tl, tm, l, min(r,tm)) + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}
// int minn (int v, int tl, int tr, int l, int r) {
// 	if (l > r)
// 		return 100000000;
// 	if (l == tl && r == tr)
// 		return t[v];
// 	int tm = (tl + tr) / 2;
// 	return  min(minn(v*2, tl, tm, l, min(r,tm)), (v*2+1, tm+1, tr, max(l,tm+1), r));
// }

int main(){
	int n, k; cin >> n >> k; 
	int a[n + 1];
	for(int i =  1; i <= n; ++i) cin >> a[i];
	build(a, 1, 1, n);
// 	for(int i = 0; i < k; ++i){
// 		int l, r; 
// 		cin >> l >> r; 
// 		cout << sum(1, 1, n, l, r) << endl; 
// 	}
	for(int i = 0; i < 28; i++) cout << t[i] << " ";
}