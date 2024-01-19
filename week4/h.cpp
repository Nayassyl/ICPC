#include <iostream>

#include <string>

using namespace std;

 

int n;

string s;

 

void gen(int p, string s)

{

  if (p == n)

  {

    cout << s << "\n";

    return;

  }

  gen(p + 1, s + "0 ");

  if (p < n - 1) gen(p + 2, s + "1 0 ");

  else gen(p + 1, s + "1 ");

}

 

int main(void)

{

  cin >> n;

  gen(0, "");

  return 0;

}