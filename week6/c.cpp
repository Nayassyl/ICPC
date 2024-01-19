#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int hIndex(vector<int> &v)
{
  for (int i = 1; i < v.size(); i++)
    if (v[i] < i) return i - 1;
  return v.size() - 1;

}
int main(){
    int n, l; 
    cin >> n >> l; 
    vector<int> v; 
    v.resize(n + 1);
    while(n--){
        int x; cin >> x; 
        v.push_back(x);
    }
    sort(v.begin() + 1, v.end(), greater<int>());
    int h = hIndex(v);
    for (int i = h + 1; i > max(h - l + 1, 0); i--) v[i]++;

    sort(v.begin() + 1, v.end(), greater<int>());
    cout << hIndex(v);
}