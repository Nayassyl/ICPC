#include <iostream>
using namespace std;
void gen(string s, int left, int right){
  if (left == 0 && right == 0)
  {
    cout << s << endl;
    return;
  }
  if (left > 0)     gen(s + "(", left - 1, right);
  if (left < right) gen(s + ")", left, right - 1);
}
int main(){
  int n;
  cin >> n;
  gen("", n, n);
}