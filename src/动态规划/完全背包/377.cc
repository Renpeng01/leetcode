#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int combinationSum4(std::vector<int> &nums, int target) {
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    // 遍历顺序不能改变
    for (int j = 0; j <= target; j++) {
      for (int i = 0; i < nums.size(); i++) {
        if ((j - nums[i]) >= 0 && dp[j] < INT_MAX - dp[j - nums[i]]) {
          dp[j] += dp[j - nums[i]];
        }
      }
    }

    return dp[target];
  }
};