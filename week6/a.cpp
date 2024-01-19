#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int main(){
	int n;
	ll k;
	cin >> n >> k; 
	vector<int> v; 
	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	int l = 0;
	int r = v.size() - 1;
	if(v[r] > k){
		cout << "Impossible"; return 0;
	}
	while (l <= r){
		if(v[r] + v[l] > k) r--;
		else {l++, r--;}
		cnt++;
	}
	cout << cnt; 

} 