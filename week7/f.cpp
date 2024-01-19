#include <iostream>
#include <vector>

int W, H;
std::vector<std::string> grid;
std::vector<std::vector<bool>> visited;

int dfs(int x, int y) {
    // Check boundaries and if the cell is land and not visited
    if(x < 0 || x >= W || y < 0 || y >= H || grid[y][x] == '#' || visited[y][x])
        return 0;

    visited[y][x] = true;  // Mark the cell as visited

    // Continue DFS in all four directions
    return 1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
}

int main() {
    int T;
    std::cin >> T;

    for(int t = 1; t <= T; ++t) {
        std::cin >> W >> H;
        grid = std::vector<std::string>(H);
        visited = std::vector<std::vector<bool>>(H, std::vector<bool>(W, false));

        int startX, startY;
        for(int i = 0; i < H; ++i) {
            std::cin >> grid[i];
            // Find the initial position of the prince
            size_t pos = grid[i].find('@');
            if(pos != std::string::npos) {
                startX = pos;
                startY = i;
            }
        }

        // Perform DFS from the initial position
        int reachableCells = dfs(startX, startY);
        std::cout << "Case " << t << ": " << reachableCells << std::endl;
    }

    return 0;
}
