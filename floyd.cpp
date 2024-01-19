#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n; cin >> n;
	int f[n][n];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> f[i][j];
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
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
