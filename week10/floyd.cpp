#include <iostream>
#include <algorithm>
int MAX = 100000007;
using namespace std;
int main(){
	freopen("floyd.in", "r", stdin);
    freopen("floyd.out", "w", stdout);
	int n; cin >> n;
	int f[n+1][n+1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> f[i][j];
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = min(f[i][j], (f[i][k] + f[k][j]));
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << f[i][j] << " ";
		}
		cout << endl;
	}

}
