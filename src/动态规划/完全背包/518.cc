#include <algorithm>
#include <iostream>
#include <vector>

// https://www.bilibili.com/video/BV1KM411k75j/?spm_id_from=333.788&vd_source=70c464e99440c207e9933663bb2e5166
class Solution {
public:
  int change(int amount, std::vector<int> &coins) {

    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    // 遍历顺序不能改变
    for (int i = 0; i < coins.size(); i++) {
      for (int j = coins[i]; j <= amount; j++) {
        dp[j] += dp[j - coins[i]];
      }
    }
    return dp[amount];
  }
};

int main() {
  Solution s;
  std::vector<int> test1 = {3, 3, 3};
  int target = 100;
  int res1 = s.change(target, test1);
  std::cout << "res1: " << res1 << std::endl;
}