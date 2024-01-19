#include <vector>
#include <queue>

bool can_reach_all(const std::vector<std::vector<int>>& roads, int n, int k, int mid) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(k + 1, 1e9));
    std::priority_queue<std::pair<int, std::pair<int, int>>> pq; // {distance, {node, remaining_charges}}

    pq.push({0, {0, k}}); // Starting from node 0 with initial charges k
    dp[0][k] = 0;

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int node = pq.top().second.first;
        int remaining_charges = pq.top().second.second;
        pq.pop();

        if (distance > dp[node][remaining_charges]) {
            continue; // Skip outdated information
        }

        for (const auto& road : roads) {
            int u = road[0], v = road[1], d = road[2];

            if (remaining_charges > 0 && distance < dp[v][remaining_charges - 1]) {
                dp[v][remaining_charges - 1] = distance;
                pq.push({-distance, {v, remaining_charges - 1}});
            }

            if (distance + d < dp[v][remaining_charges]) {
                dp[v][remaining_charges] = distance + d;
                pq.push({-(distance + d), {v, remaining_charges}});
            }
        }
    }

    for (int i = 0; i <= k; ++i) {
        if (dp[n - 1][i] <= mid) {
            return true;
        }
    }

    return false;
}