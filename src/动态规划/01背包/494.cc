// 这里，我们可以把状态定义为dp[i][j]，表示用数组中前i个元素组成和为j的方案数。那么状态转移方程就是：
// dp[i][j]= dp[i-1][j-nums[i]] + dp[i-1][j+nums[i]]
// 这个方程的意思是，如果我们要用前i个元素组成和为j的方案数，
// 那么有两种选择：第i个元素取正号或者取负号。如果取正号，那么前i-1个元素就要组成和为j-nums[i]的方案数；如果取负号，那么前i-1个元素就要组成和为j+nums[i]的方案数。
// 所以两种选择的方案数相加就是dp[i][j]。
// 但是这样定义状态会导致空间复杂度过高，因为我们需要一个二维数组来存储所有可能的状态。所以我们可以对问题进行一些变换，把它转化为一个背包问题。
// 我们可以把数组中所有取正号的元素看作一个集合P，所有取负号的元素看作一个集合N。那么有：
// sum(P) - sum(N) = target
// sum(P) + sum(N) = sum(nums)
// 两式相加得：
// sum(P) = (target + sum(nums)) / 2
// 也就是说，我们只需要找到有多少种方法可以从数组中选出若干个元素使得它们的和等于(target
// + sum(nums)) / 2即可。这就变成了一个经典的01背包问题。
// 所以我们可以把状态定义为dp[j]，表示用数组中若干个元素组成和为j的方案数。那么状态转移方程就是：
// dp[j] = dp[j] + dp[j - nums[i]]
// 这个方程的意思是，如果我们要用若干个元素组成和为j的方案数，那么有两种选择：不选第i个元素或者选第i个元素。如果不选第i个元素，那么原来已经有多少种方案数就不变；如果选第i个元素，那么剩下要组成和为
// j- nums[i] 的方案数就等于dp[j - nums[i]]。所以两种选择相加就是dp[j]。
// 但是在实现这个状态转移方程时，有一个细节需要注意：由于每次更新dp[j]都依赖于之前计算过得dp值（也就是说当前行依赖于上一行），所以我们必须从后往前遍历更新dp值（也就是说从右往左更新），否则会覆盖掉之前需要用到得值。
// 最后返回dp[bag_size]即可

#include <iostream>
#include <vector>
class Solution {
public:
  int findTargetSumWays(std::vector<int> &nums, int target) {
    int sum = 0;
    for (auto a : nums) {
      sum += a;
    }

    int tmp = sum + target;
    if (tmp % 2 == 1) {
      return 0;
    }
    if (abs(target) > sum)
      return 0;
    int newTarget = (target + sum) / 2;
    std::vector<int> dp(newTarget + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = newTarget; j >= nums[i]; j--) {
        dp[j] = dp[j] + dp[j - nums[i]];
      }
    }

    return dp[newTarget];
  }
};

int main() {
  Solution s;
  std::vector<int> test1 = {1, 1, 1, 1, 1};
  int target = 3;
  int res1 = s.findTargetSumWays(test1, target);
  std::cout << "res1: " << res1 << std::endl;
}