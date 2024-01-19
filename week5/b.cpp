#include <iostream>
using namespace std;
#define ll long long
ll t[8000000];
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
        t[index] = t[2 * index] + t[2 * index + 1];
    }
}
void update(int index, int left, int right, int pos, int data){
	if (left == right){
		t[index] = data;
	}
	else{
		int mid = (left + right) / 2;
		if(pos <= mid)
			update(2 * index, left, mid, pos, data);
		else
			update(2 * index + 1, mid + 1, right, pos, data);
		t[index] = t[index * 2] + t[2 * index + 1];
	}
}
ll sum(int index, int left, int right , int queryleft, int queryright) {
	if (queryleft > queryright)
		return 0LL;
	if (queryleft == left && queryright == right)
		return t[index];
	int mid = (left + right) / 2;
	return sum(index * 2, left, mid, queryleft, min(queryright,mid)) + sum (index * 2 + 1, mid + 1 , right , max(queryleft,mid + 1), queryright);
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
    	char a;
    	int m, k; 
    	cin >> a >> m >> k; 
    	if ( a == 'A')
    		update(1, 1, n, m, k);
    	else
    		cout << sum(1, 1, n, m, k) << "\n";
    }
}