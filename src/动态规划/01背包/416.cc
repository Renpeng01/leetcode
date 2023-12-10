#include <algorithm>
#include <iostream>
#include <vector>
void printDp(std::vector<int> dp);
class Solution {
public:
  bool canPartition(std::vector<int> &nums) {
    int bagSize = 0;
    int sum = 0;
    for (auto v : nums) {
      sum += v;
    }

    if (sum % 2 == 1) {
      return false;
    }
    bagSize = sum / 2;

    std::vector<int> dp(bagSize + 1, 0);
    for (int i = 0; i < nums.size(); i++) {
      for (int j = bagSize; j >= nums[i]; j--) {
        dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }

    // std::cout << "dp[bagSize]: " << dp[bagSize] << " bagSize: " << bagSize
    //           << std::endl;
    // printDp(dp);
    if (dp[bagSize] == bagSize) {
      return true;
    }
    return false;
  }
};

void printDp(std::vector<int> dp) {
  for (int i = 0; i < dp.size(); i++) {
    std::cout << "i:" << i << " dp[i]: " << dp[i] << std::endl;
  }
}

int main() {
  Solution s;
  std::vector<int> test1 = {1, 5, 11, 5};
  bool res = s.canPartition(test1);
  std::cout << "res:" << res << std::endl;
}