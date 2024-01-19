#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool compareUpgrades(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

double minTimeToDestination(int l, int v, int n, vector<vector<int>>& upgrades) {
    // Sort the upgrades based on time
    sort(upgrades.begin(), upgrades.end(), compareUpgrades);

    // Initialize variables
    double totalTime = 0;
    int currentSpeed = v;

    // Iterate through the upgrades
    for (const vector<int>& upgrade : upgrades) {
        int speedIncrease = upgrade[0];
        int upgradeTime = upgrade[1];

        // Calculate time with the current speed
        double timeWithCurrentSpeed = static_cast<double>(l) / currentSpeed;

        // Calculate time with the upgraded speed
        int upgradedSpeed = currentSpeed + speedIncrease;
        double timeWithUpgrade = static_cast<double>(l) / upgradedSpeed + upgradeTime;

        // Choose the minimum time between the current speed and the upgraded speed
        if (timeWithCurrentSpeed < timeWithUpgrade) {
            totalTime += timeWithCurrentSpeed;
            break;
        } else {
            totalTime += upgradeTime;
            currentSpeed = upgradedSpeed;
        }
    }

    // Calculate the remaining time with the final speed
    totalTime += static_cast<double>(l) / currentSpeed;

    return totalTime;
}

int main() {
    // Input
    int l, v, n;
    cin >> l >> v >> n;
    vector<vector<int>> upgrades(n, vector<int>(2));

    for (int i = 0; i < n; ++i) {
        cin >> upgrades[i][0] >> upgrades[i][1];
    }

    // Output
    double result = minTimeToDestination(l, v, n, upgrades);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
