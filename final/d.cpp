#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int getMaxRun(int x, int y, int last_diff, const std::vector<std::vector<int>>& buildings, std::vector<std::vector<std::vector<int>>>& dp, int max_diff) {
    last_diff = std::min(last_diff, max_diff);

    if (dp[x][y][last_diff] != -1) return dp[x][y][last_diff];

    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int max_run = 1;
    
    for (int i = 0; i < 4; ++i) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        
        if (isValid(nx, ny, buildings.size(), buildings[0].size())) {
            int height_diff = buildings[nx][ny] - buildings[x][y];
            if (height_diff > 0 && height_diff > last_diff) {
                max_run = std::max(max_run, 1 + getMaxRun(nx, ny, height_diff, buildings, dp, max_diff));
            }
        }
    }
    
    dp[x][y][last_diff] = max_run;
    return max_run;
}

int maxGoodRun(std::vector<std::vector<int>>& buildings) {
    int n = buildings.size();
    int m = buildings[0].size();

    int max_height = INT_MIN;
    int min_height = INT_MAX;
    for (const auto& row : buildings) {
        for (int height : row) {
            max_height = std::max(max_height, height);
            min_height = std::min(min_height, height);
        }
    }
    int max_diff = max_height - min_height;

    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(max_diff + 1, -1)));
    
    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            max_length = std::max(max_length, getMaxRun(i, j, 0, buildings, dp, max_diff));
        }
    }
    
    return max_length;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> buildings(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> buildings[i][j];
        }
    }
    
    std::cout <<  maxGoodRun(buildings);
    return 0;
}
