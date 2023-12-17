#include <vector>

// dp[i][0] 持有股票最大值
// dp[i][1] 不持有股票最大值
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
      dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return std::max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
  }
};
