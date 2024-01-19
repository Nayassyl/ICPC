#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main()
{   size_t n, k;
    cin >> n >> k;
    vector<size_t> a(n);
    for(auto& e : a) cin >> e;
 
    sort(a.begin(), a.end());
 
    size_t left  = 0;
    size_t right = a.back() - a[0] + 1;
 
    while(left < right)
    {
        size_t mid  = (left + right)/2;
        size_t cows = 1;
        size_t last = a[0];
 
        for(size_t i = 1; i < n; ++i)
        {
            auto cur = a[i];
            if(cur - last > mid)
            {   cows +=  1;
                last = cur;
            }
        }
 
        if(cows >= k) left  = mid+1;
        else          right = mid;
    }
 
    cout << left;
}
