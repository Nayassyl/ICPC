#include <iostream>
using namespace std; 
#define str string
int main(){
    bool check = false;
    int n; cin >> n; 
    str a, b; 
    cin >> a >> b; 
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]){
            if(!check){
                check = true;
                cnt++;
            }
        }
        else check = false;
    }
    cout << cnt;
}