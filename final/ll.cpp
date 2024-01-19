#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> countA;  // Текущее количество каждого a
    unordered_map<int, int> requiredB;  // Необходимое количество для каждого a
    vector<int> a_values(n);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        countA[a]++;
        requiredB[a] = b;
        a_values[i] = a;
    }

    int operations = 0;

    for (int a : a_values) {
        // Если текущее количество a больше требуемого
        while (countA[a] > requiredB[a]) {
            countA[a]--;
            operations++;
        }
        // Если текущее количество a меньше требуемого
        while (countA[a] < requiredB[a]) {
            countA[a]++;
            operations++;
        }
    }

    cout << operations << endl;
    return 0;
}
