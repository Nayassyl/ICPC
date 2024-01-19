#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> h(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }

    int cnt = 0;
    int ind = max_element(h.begin(), h.end()) - h.begin();
    while (h[ind] > 0)
    {
        h[ind] -= a;
        for (int i = 0; i < h.size(); ++i)
        {
            if (i == ind)
                continue;
            if (h[i] <= b)
                h.erase(h.begin(), h.begin() + i);
            h[i] -= b;
        }
        cnt++;
        ind = max_element(h.begin(), h.end()) - h.begin();
    }
    cout << cnt;
    return 0;
}