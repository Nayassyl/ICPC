#include <iostream>
using namespace std;
#define ll long long 
ll t[8000000];
void build(int a[], int index, int left, int right){
	if(left == right){
		t[index] = a[left];
	}
	else{
		int m = (left + right)/2;
		build(a, 2*index,  left, m);
		build(a, 2*index + 1, m+1, right);
		t[index] = min(t[2*index], t[2*index + 1]);
	}
}
int minn (int index, int tleft, int tright, int left, int right) {
	if (left > right)
		return 100000000;
	if (left == tleft && right == tright)
		return t[index];
	int tm = (tleft + tright) / 2;
	return  min(minn(index*2, tleft, tm, left, tm), minn(index*2+1, tm+1, tright, tm  + 1, right));
}

int main(){
	int n, k; cin >> n >> k; 
	int a[n + 1];
	for(int i =  1; i <= n; ++i) cin >> a[i];
	build(a, 1, 1, n);
	for(int i = 0; i < k; ++i){
		int left, right; 
		cin >> left >> right; 
		cout << minn(1, 1, n, left, right) << endl; 
	}
}