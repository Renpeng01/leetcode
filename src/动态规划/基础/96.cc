#include <iostream>
#include <vector>

class Solution {
public:
  int numTrees(int n) {
    std::vector<int> dp(n + 1);
    if (n <= 1) {
      return 1;
    }
    if (n <= 2) {
      return 2;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += (dp[j - 1] * dp[i - j]);
      }
    }

    return dp[n];
  }
};

int main() {
  Solution s;
  int n1 = 3;
  std::cout << "n = " << n1 << " res = " << s.numTrees(n1) << std::endl;

  int n2 = 19;
  std::cout << "n = " << n2 << " res = " << s.numTrees(n2) << std::endl;
}