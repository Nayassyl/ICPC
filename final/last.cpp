#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> countA;
    unordered_map<int, int> bValues;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        countA[a]++;
        bValues[a] = b;
    }

    int operations = 0;
    for (auto &pair : countA) {
        int a = pair.first;
        int count = pair.second;
        int required = bValues[a];
        operations += min(abs(count - required), count);
    }

    for (auto &pair : bValues) {
        if (countA.find(pair.first) == countA.end() && pair.second != 0) {
            operations += pair.second;
        }
    }

    cout << operations << endl;
    return 0;
}
