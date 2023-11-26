#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int begin = 0;
    int max = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] <= prices[begin]) {
        begin = i;
      } else {
        max = std::max(max, prices[i] - prices[begin]);
      }
    }
    return max;
  }
};

int main() {

  Solution s;
  std::vector<int> test1 = {7, 1, 5, 3, 6, 4};
  int res = s.maxProfit(test1);
  std::cout << res << std::endl;
}