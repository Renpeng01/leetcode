#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printDp(std::vector<std::vector<int>> &dp) {
  for (int i = 0; i < dp.size(); i++) {
    std::string s;
    for (auto a : dp[i]) {
      s += " " + std::to_string(a);
    }
    std::cout << s << std::endl;
  }
}

// ******************【01背包】******************

//       重量  价值
// 物品0   1     15
// 物品1   3     20
// 物品2   4     30
// 背包最大能装4

//  dp[i][j] 0~i物品任取放入容量j的背包里的的最大价值为dp[i][j]

// 不放i  dp[i-1][j]
// 方i    dp[i-1][j - weight[i]] + value[i]
// 取max  dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i])

// https://www.bilibili.com/video/BV1BU4y177kY/?spm_id_from=333.788&vd_source=70c464e99440c207e9933663bb2e5166
class Solution {
public:
  // 二维dp数组的实现
  int func(std::vector<int> weight, std::vector<int> value, int beg) {
    int goods = weight.size();
    std::vector<std::vector<int>> dp;
    for (int i = 0; i < goods; i++) {
      dp.push_back(std::vector<int>(beg + 1));
    }

    for (int i = 1; i <= beg; i++) {
      if (weight[0] > i) {
        continue;
      }
      dp[0][i] = value[0];
    }

    for (int i = 1; i < goods; i++) {
      for (int j = 0; j <= beg; j++) {
        // 这个判断容易忽略 （当无法装下weightw为i的时候）
        if (j - weight[i] < 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] =
              std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
      }
    }
    // printDp(dp);

    return dp[goods - 1][beg];
  }

  //  一维dp数组的实现 （滚动数组）
  int func1(std::vector<int> weight, std::vector<int> value, int beg) {
    std::vector<int> dp(beg + 1, 0);
    int goods = weight.size();

    for (int i = 0; i < goods; i++) {
      // ***********************  这里的遍历顺序是重点，是倒序
      for (int j = beg; j >= weight[i]; j--) {
        // 这个判断容易忽略 （当无法装下weightw为i的时候）
        if (j - weight[i] < 0) {
          dp[j] = dp[j];
        } else {
          dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
      }
    }
    return dp[beg];
  }
};

// ****************** 【完全背包】******************
// 物品可以使用无数次
// https://www.bilibili.com/video/BV1uK411o7c9/?spm_id_from=333.788&vd_source=70c464e99440c207e9933663bb2e5166

class Solution1 {
public:
  // 将01背包的以为数组的遍历顺序从倒序改为正序
  int func2(std::vector<int> weight, std::vector<int> value, int beg) {
    std::vector<int> dp(beg + 1, 0);
    int goods = weight.size();

    for (int i = 0; i < goods; i++) {
      // ***********************  这里的遍历顺序是重点
      // (仅仅与01背包的遍历顺序不同)
      for (int j = weight[i]; j <= beg; j++) {
        // 这个判断容易忽略 （当无法装下weightw为i的时候）
        if (j - weight[i] < 0) {
          dp[j] = dp[j];
        } else {
          dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
      }
    }
    return dp[beg];
  }
};

int main() {
  Solution s;
  std::vector<int> weight = {1, 3, 4};
  std::vector<int> value = {15, 20, 30};
  int beg = 4;

  int res = s.func(weight, value, beg);
  std::cout << "func: " << res << std::endl;

  int res1 = s.func1(weight, value, beg);
  std::cout << "func1: " << res1 << std::endl;

  Solution1 s1;
  int res2 = s1.func2(weight, value, beg);
  std::cout << "func2: " << res2 << std::endl;
}
