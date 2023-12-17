#include <vector>

// dp[i][0] 持有股票最大值
// dp[i][1] 保持卖出股票的状态
// dp[i][2] 卖出股票的状态
// dp[i][3] 冷冻期
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.size() == 0)
      return 0;
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(4));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 0;
    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = std::max(dp[i - 1][0], std::max(dp[i - 1][1] - prices[i],
                                                 dp[i - 1][3] - prices[i]));
      dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][3]);
      dp[i][2] = dp[i - 1][0] + prices[i];
      dp[i][3] = dp[i - 1][2];
    }

    return std::max(
        dp[prices.size() - 1][1],
        std::max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
  }
};
