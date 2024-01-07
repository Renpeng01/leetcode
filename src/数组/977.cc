#include <vector>

class Solution {
public:
  std::vector<int> sortedSquares(std::vector<int> &nums) {
    std::vector<int> res(nums.size(), 0);
    int head = 0, tail = nums.size() - 1;
    for (int i = res.size() - 1; i >= 0; i--) {
      if (abs(nums[head]) > abs(nums[tail])) {
        res[i] = pow(nums[head], 2);
        head++;
      } else {
        res[i] = pow(nums[tail], 2);
        tail--;
      }
    }
    return res;
  }
};