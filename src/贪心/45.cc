#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int jump(std::vector<int> &nums) {
    if (nums.size() <= 1) {
      return 0;
    }

    int result = 0;
    int nextCover = 0;
    int curCover = 0;

    for (int i = 0; i < nums.size(); i++) {
      nextCover = std::max(i + nums[i], nextCover);
      if (i == curCover) {
        if (curCover != (nums.size() - 1)) {
          result++;
          curCover = nextCover;
          if (curCover >= (nums.size() - 1)) {
            break;
          }
        } else {
          break;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  std::vector<int> test1 = {1, 2, 1, 1, 1};
  std::cout << s.jump(test1) << std::endl;

  // std::vector<int> test2 = {3, 2, 1, 0, 4};
  // std::cout << s.jump(test2) << std::endl;

  // std::vector<int> test3 = {2, 0, 0};
  // std::cout << s.jump(test3) << std::endl;
}