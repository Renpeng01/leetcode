#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// https://www.bilibili.com/video/BV1rW4y1x7ZQ/?spm_id_from=333.788&vd_source=70c464e99440c207e9933663bb2e5166

class Solution {
public:
  int findMaxForm(std::vector<std::string> &strs, int m, int n) {
    std::vector<std::vector<int>> dp(m + 1,
                                     std::vector<int>(n + 1, 0)); // 默认初始化0

    for (auto str : strs) {
      int oneNum = 0, zeroNum = 0;
      for (char c : str) {
        if (c == '0')
          zeroNum++;
        else
          oneNum++;
      }

      for (int i = m; i >= zeroNum; i--) {
        for (int j = n; j >= oneNum; j--) {
          dp[i][j] = std::max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
        }
      }
    }

    return dp[m][n];
  }
};

int main() { Solution s; }