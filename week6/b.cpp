#include <iostream>
#include <algorithm>
using namespace std; 
int count(string x, string s){
    int count = 0;
    for (int i = 0; i < s.size() - 1; i++){
        if (s[i] == x[0] && s[i + 1] == x[1]){
            count += 1;
        }
    }
    return count;
}
int main(){
    int n; cin >> n; 
    string a, b; 
    cin >> a >> b; 
    string st = "";
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) st += '1';
        else st += '0';
    }
    st = '0' + st + '0';
    cout << (count("01", st) + count("10", st))/2;

} 
