
#include <algorithm>
#include <vector>

class Solution {
public:
  int findLengthOfLCIS(std::vector<int> &nums) {
    std::vector<int> dp(nums.size(), 1);
    if (nums.size() == 0) {
      return 0;
    }
    int max = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        dp[i] = dp[i - 1] + 1;
      }

      if (dp[i] > max) {
        max = dp[i];
      }
    }

    return max;
  }
};