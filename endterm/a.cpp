#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a, b, c; 
	cin >> a >> b >> c; 
	if (a%2 ==0 && ((a+b)%2==1 || (a+c)%2==1)) cout << "YES";
	else if (a%2 ==1 && ((a+b)%2==1 || (a+c)%2==1)) cout << "YES";
    else cout << "NO";
}