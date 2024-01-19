def max_good_run(buildings):
    def is_valid(x, y):
        return 0 <= x < len(buildings) and 0 <= y < len(buildings[0])
    
    def get_max_run(x, y):
        # If already calculated, return the result
        if dp[x][y] != -1:
            return dp[x][y]
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # Right, Down, Left, Up
        max_run = 1  # Minimum run length is 1 (the building itself)
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if is_valid(nx, ny) and buildings[nx][ny] > buildings[x][y]:
                max_run = max(max_run, 1 + get_max_run(nx, ny))
        
        dp[x][y] = max_run
        return max_run

    # Initialize the dp array with -1 indicating uncalculated values
    dp = [[-1 for _ in range(len(buildings[0]))] for _ in range(len(buildings))]
    
    # Calculate the maximum good run starting from each building
    max_length = 0
    for i in range(len(buildings)):
        for j in range(len(buildings[0])):
            max_length = max(max_length, get_max_run(i, j))
    
    return max_length

n, m = [int(i) for i in input().split()]
bb = [[int(i) for i in input().split()] for j in range(n)]
print(max_good_run(bb))