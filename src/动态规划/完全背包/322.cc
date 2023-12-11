#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        if (dp[j - coins[i]] != INT_MAX) {
          dp[j] = std::min(dp[j - coins[i]] + 1, dp[j]);
        }
      }
    }
    if (dp[amount] == INT_MAX)
      return -1;
    return dp[amount];
  }
};