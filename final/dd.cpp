#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int getMaxRun(int x, int y, int last_diff, const vector<vector<int>>& buildings, vector<vector<vector<int>>>& dp, int max_diff) {
    last_diff = min(last_diff, max_diff);
    if (dp[x][y][last_diff] != -1) return dp[x][y][last_diff];
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int max_run = 1;  
    for (int i = 0; i < 4; ++i) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (isValid(nx, ny, buildings.size(), buildings[0].size())) {
            int height_diff = buildings[nx][ny] - buildings[x][y];
            if (height_diff > 0 && height_diff > last_diff) {
                max_run = max(max_run, 1 + getMaxRun(nx, ny, height_diff, buildings, dp, max_diff));
            }
        }
    }
    dp[x][y][last_diff] = max_run;
    return max_run;
}

int maxGoodRun(vector<vector<int>>& buildings) {
    int n = buildings.size();
    int m = buildings[0].size();
    int max_height = INT_MIN;
    int min_height = INT_MAX;
    for (const auto& row : buildings) {
        for (int height : row) {
            max_height = max(max_height, height);
            min_height = min(min_height, height);
        }
    }
    int max_diff = max_height - min_height;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(max_diff + 1, -1)));
    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            max_length = max(max_length, getMaxRun(i, j, 0, buildings, dp, max_diff));
        }
    }
    return max_length;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> buildings(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> buildings[i][j];
        }
    }
    cout << maxGoodRun(buildings);
    return 0;
}
