#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
int t[4000000];
void build(int a[], int index, int left, int right)
{
    if (left == right)
    {
        t[index] = a[left];
    }
    else
    {
        int m = (left + right) / 2;
        build(a, 2 * index, left, m);
        build(a, 2 * index + 1, m + 1, right);
    }
}
void update(int index, int left, int right, int queryleft, int queryright, int add){
	if (queryleft > queryright)
		return;
	if (queryleft == left && queryright == right)
		t[index] += add;
	else{
		int mid = (left + right) / 2;
		update(index * 2, left, mid, queryleft, min(queryright,mid), add);
		update(index * 2 + 1, mid + 1 , right , max(queryleft,mid + 1), queryright, add);
	}
}

int get(int index, int left, int right, int pos){
	if (left == right){
		return t[index];
	}
	else{
		int mid = (left + right) / 2;
		if(pos <= mid)
			return t[index] + get(2 * index, left, mid, pos);
		else
			return t[index] + get(2 * index + 1, mid + 1, right, pos);
	}
}

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        a[i] = 0;
    build(a, 1, 1, n);
    while(q--){
    	char s;
    	int a, b, c; 
    	cin >> s; 
    	if(s == 'A'){
    		cin >> a >> b >> c; 
    		update(1, 1, n, a, b, c);
    	}
    	else{
    		cin >> a; 
    		cout << get(1, 1, n, a) << "\n";
    	}
    }
}