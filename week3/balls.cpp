#include <iostream>
using namespace std; 
int summ(int n){
    return (n * (n+1))/2;
}
int main(){
    // int n; cin >> n; 
    // while(n--){
    //     int a; cin >> a; 
    // }
    int arr[122];
    arr[0] = 0;
    for(int i = 1; i < 122; i++){
        arr[i] = arr[i-1] + summ(i);
        cout << arr[i] << " ";
    }
}