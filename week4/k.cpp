#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int b[n], a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = i + 1;
    }
    int c = 1;
    bool check = true;
    do
    {
        for (int i = 0; i < n - 1; i++){
            if (a[i] != b[i]){
                check = false;
                break;
            }
        }
        if(!check)c++;
        check = !check;
    } while (next_permutation(b, b + n) and check == true);
    cout << c;
}
