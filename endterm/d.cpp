#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
int t[400000];
int i, j, n, k, z, q, pos, value;
char c;
int sgn(int n)
{
  return (n > 0) - (n < 0);
}

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
        t[index] = (t[2*index] * t[2*index+ 1]);
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
		t[index] = (t[index * 2] * t[2 * index + 1]);
	}
}
int get(int index, int left, int right , int queryleft, int queryright) {
	if (queryleft > queryright)
		return 1;
	if (queryleft == left && queryright == right)
		return t[index];
	int mid = (left + right) / 2;
	return get(index * 2, left, mid, queryleft, min(queryright,mid))* get(index * 2 + 1, mid + 1 , right , max(queryleft,mid + 1), queryright);
}

int main(void)
{
	int a[100000];
  while(scanf("%d %d",&n,&k) == 2)
  {
    for(i = 1; i <= n; i++)
    {
      scanf("%d",&a[i]);
      a[i] = sgn(a[i]);
    }
    build(a,1,1,n);
	for(z = 0; z < k; z++)
    {
      scanf("\n%c",&c);
      if (c == 'C')
      {
        scanf("%d %d\n",&pos,&value);
        value = sgn(value);
        update(1,1,n,pos,value);
      }
      else
      {
        scanf("%d %d\n",&i,&j);
        q = get(1,1,n,i,j);
        if(q == 1) printf("+"); else
        if(q == 0) printf("0"); else printf("-");
      }
    }
    printf("\n");
  }
  return 0;
}