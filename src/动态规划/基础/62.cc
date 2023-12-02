#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp;
    for (int i = 0; i < m; i++) {
      dp.push_back(std::vector<int>(n, 0));
    }

    for (int i = 0; i < n; i++) {
      dp[0][i] = 1;
    }

    for (int i = 0; i < m; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main() {
  Solution s;
  int m1 = 3, n1 = 7;
  std::cout << "m = " << m1 << " n = " << n1
            << " res = " << s.uniquePaths(m1, n1) << std::endl;

  int m2 = 3, n2 = 2;
  std::cout << "m = " << m2 << " n = " << n2
            << " res = " << s.uniquePaths(m2, n2) << std::endl;
}