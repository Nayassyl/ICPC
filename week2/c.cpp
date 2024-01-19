#include <iostream>
using namespace std; 
#include <vector>
#include <algorithm>
class segment
{
public:
  int start, fin;
  segment(int start, int fin) : start(start), fin(fin) {}
};
vector<segment> v;
int f(segment a, segment b)
{
  return a.fin <= b.fin;
}
int main(){
    int n; cin >> n;
    while (n--){
        int a, b; 
        cin >> a >> b;
        v.push_back(segment(a, b));
    }
    sort(v.begin(), v.end(), f);
    int cur = 0; 
    int res = 1;
    for (int i = 1; i < v.size(); i++){
        if (v[i].start >= v[cur].fin){
            cur = i;
            res++;
        }
    }
    cout << res;
}