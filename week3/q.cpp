#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubsequence(const vector<int>& seq) {
    int n = seq.size();
    vector<int> dp(n, 1);  // Initialize all values to 1

    for (int i = 1; i < n; i++) {  // Start from the second element
        for (int j = 0; j < i; j++) {  // Check all elements before the i-th
            if (seq[i] > seq[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;  // Update the LIS length for the i-th element
            }
        }
    }

    // Find the maximum length from the dp array
    int max_length = 0;
    for (int length : dp) {
        if (length > max_length) {
            max_length = length;
        }
    }
    return max_length;
}

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    cout << longestIncreasingSubsequence(seq) << endl;
    return 0;
}
