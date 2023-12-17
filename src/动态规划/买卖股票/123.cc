#include <vector>

// dp[i][0] 不操作
// dp[i][1] 第一次持有
// dp[i][2] 第一次不持有
// dp[i][3] 第二次持有
// dp[i][4] 第二次不持有
// https://www.bilibili.com/video/BV1WG411K7AR/?spm_id_from=333.788&vd_source=70c464e99440c207e9933663bb2e5166
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    dp[0][3] = -prices[0];
    dp[0][4] = 0;

    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
      dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
      dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[prices.size() - 1][4];
  }
};
