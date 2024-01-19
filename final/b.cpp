#include <iostream>
using namespace std;
#define ll long long
ll t[4004];
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
        t[index] = max(t[2 * index], t[2 * index + 1]);
    }
}
void update(int index, int left, int right,int data, int X){
	if (t[left] == data && t[right] == data){
		t[right] -= X;
	}
	else{
		int mid = (left + right) / 2;
		if(data <= t[mid])
			update(2 * index, left, mid,data, X);
		else
			update(2 * index + 1, mid + 1, right, data, X);
		t[index] = max(t[index * 2], t[2 * index + 1]);
	}
}

int main()
{
    int n, X;
    cin >> n >> X;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(a, 1, 1, n);
    // int cnt = 0;
    // while(t[1] > 0){
    //     int s = t[1]; 
    //     update(1, 1, n, s, X);
    //     X = (X+1) / 2;
    //     cnt++;
    // }
    // cout << cnt; 
    for(int i = 1; i <= 22; i++){
        cout<<  t[i] << " "; 
    }
}
