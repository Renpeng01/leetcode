#include <iostream>
#include <vector>

void printDp(std::vector<int> dp) {
  for (int i = 0; i < dp.size(); i++) {
    std::cout << i << std::endl;
  }
}

class Solution {
public:
  int fib(int n) {
    std::vector<int> dp(n + 1, 0);

    // std::cout << "size: " << dp.size() << std::endl;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    // printDp(dp);
    return dp[n];
  }

  // 优化db的存储，不需要存储全部旧值，只需要存储前2位即可
  int fib2(int n) {

    int p0 = 0;
    int p1 = 1;
    int sum = 0;

    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }

    for (int i = 2; i <= n; i++) {
      sum = p0 + p1;
      p0 = p1;
      p1 = sum;
    }

    return sum;
  }
};

int main() {
  Solution s;
  int n1 = 2;
  std::cout << "n=" << n1 << " fib1=" << s.fib2(n1) << std::endl;
  std::cout << "n=" << n1 << " fib2=" << s.fib2(n1) << std::endl;

  int n2 = 3;
  std::cout << "n=" << n2 << " fib1=" << s.fib2(n2) << std::endl;
  std::cout << "n=" << n2 << " fib2=" << s.fib2(n2) << std::endl;
}
