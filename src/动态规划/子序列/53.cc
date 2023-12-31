#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int max = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
      if (dp[i] > max) {
        max = dp[i];
      }
    }
    return max;
  }
};