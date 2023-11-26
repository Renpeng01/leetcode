#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    if (nums.size() <= 1) {
      return true;
    }
    int maxCover = 0;
    for (int i = 0; i < nums.size(); i++) {
      maxCover = std::max(i + nums[i], maxCover);
      if (maxCover >= (nums.size() - 1)) {
        return true;
      }
      if (maxCover > i) {
        continue;
      } else {
        return false;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  std::vector<int> test1 = {2, 3, 1, 1, 4};
  std::cout << std::boolalpha << s.canJump(test1) << std::endl;

  std::vector<int> test2 = {3, 2, 1, 0, 4};
  std::cout << std::boolalpha << s.canJump(test2) << std::endl;

  std::vector<int> test3 = {2, 0, 0};
  std::cout << std::boolalpha << s.canJump(test3) << std::endl;
}