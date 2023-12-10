#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int lastStoneWeightII(std::vector<int> &stones) {
    int sum = 0;
    for (auto s : stones) {
      sum += s;
    }
    int bagSize = sum / 2;

    std::vector<int> dp(1501, 0);

    for (int i = 0; i < stones.size(); i++) {
      for (int j = bagSize; j >= stones[i]; j--) {
        dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }

    return sum - 2 * dp[bagSize];
  }
};

int main() {
  Solution s;
  std::vector<int> test1 = {2, 7, 4, 1, 8, 1};
  int target = 3;
  int res1 = s.lastStoneWeightII(test1);
  std::cout << "res1: " << res1 << std::endl;
}