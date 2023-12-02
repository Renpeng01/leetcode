#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {
    std::vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i < dp.size(); i++) {
      dp[i] = std::min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]));
    }
    return dp[dp.size() - 1];
  }
};

int main() {
  Solution s;
  std::vector<int> cost1 = {10, 15, 20};
  std::cout << "cost1 res: " << s.minCostClimbingStairs(cost1) << std::endl;

  std::vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  std::cout << "cost2 res: " << s.minCostClimbingStairs(cost2) << std::endl;
}