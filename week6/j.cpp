#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    freopen("justforfood.in", "r", stdin);
    freopen("justforfood.out", "w", stdout);
    int n, m;

    std::cin >> n >> m; // Read n and m

    std::vector<int> countFoods(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> countFoods[i]; // Read the count for each food type
    }

    // Sort the counts in ascending order
    std::sort(countFoods.begin(), countFoods.end());

    // Variables to track the maximum number of teams and the current minimum count
    long long maxTeams = 0;

    // Calculate the maximum number of teams
    for (int i = 0; i + m <= n; ++i) {
        // Calculate the number of teams that can be formed with the current selection of m counts
        long long teamsWithCurrentSelection = countFoods[i] * (long long)m;
        maxTeams = std::max(maxTeams, teamsWithCurrentSelection);
    }

    std::cout << maxTeams << std::endl; // Print the maximum number of teams

    return 0;
}
