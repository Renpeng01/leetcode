#include <algorithm>
#include <vector>

class Solution {
public:
  int lengthOfLIS(std::vector<int> &nums) {
    std::vector<int> dp(nums.size(), 1);

    if (nums.size() == 0) {
      return 0;
    }
    int max = 1;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = std::max(dp[j] + 1, dp[i]);
        }
      }

      if (dp[i] > max) {
        max = dp[i];
      }
    }

    return max;
  }
};

int main() {}