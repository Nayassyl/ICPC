#include <iostream>
#include <cstring>
using namespace std; 
#include <algorithm>
#define MAX 1001
int a[MAX][MAX], s[MAX][MAX];
int main(){
    int n, m, i, j; 
    cin >> n >> m ; 
    for(i = 1; i <= n ; i++)
        for(j = 1; j <= m; j++)
            cin >> a[i][j];
        

    memset(s,0,sizeof(s));
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
}