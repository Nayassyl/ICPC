#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minScore(vector<int>& cards) {
    int n = cards.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                int cost = cards[i] * cards[k] * cards[j] + dp[i][k] + dp[k][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> cards(n+2);
    cards[0] = 1; // Add a virtual card at the beginning
    cards[n+1] = 1; // Add a virtual card at the end
    for(int i = 1; i <= n; ++i) {
        cin >> cards[i];
    }
    cout << minScore(cards) << endl;
    return 0;
}
