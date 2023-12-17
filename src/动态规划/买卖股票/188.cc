#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProfit(int k, std::vector<int> &prices) {
    std::vector<std::vector<int>> dp(prices.size(),
                                     std::vector<int>(2 * k + 1, 0));
    if (prices.size() == 0)
      return 0;

    for (int j = 1; j < 2 * k; j += 2) {
      dp[0][j] = -prices[0];
    }
    for (int i = 1; i < prices.size(); i++) {
      for (int j = 0; j < 2 * k - 1; j = j + 2) {
        dp[i][j + 1] = std::max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
        dp[i][j + 2] = std::max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
      }
    }
    return dp[prices.size() - 1][2 * k];
  }
};
