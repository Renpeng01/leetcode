#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int numSquares(int n) {
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
      for (int j = i * i; j <= n; j++) {
        if (dp[j - i * i] != INT_MAX) {
          dp[j] = std::min(dp[j - i * i] + 1, dp[j]);
        }
      }
    }
    if (dp[n] == INT_MAX)
      return -1;
    return dp[n];
  }
};