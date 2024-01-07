#include <iostream>
#include <vector>

class Solution {
public:
  // 首尾指针
  int removeElement(std::vector<int> &nums, int val) {
    int head = 0, tail = nums.size() - 1;
    while (true) {
      while (head <= tail) {
        if (nums[head] != val) {
          head++;
        } else {
          break;
        }
      }
      while (tail >= head) {
        if (nums[tail] == val) {
          tail--;
        } else {
          break;
        }
      }
      if (tail <= head) {
        return tail + 1;
      }
      nums[head] = nums[tail];
      head++;
      tail--;
    }
  }

  // 快慢指针
  int removeElement1(std::vector<int> &nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); fast++) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
      }
    }
    return slow;
  }
};

int main() {
  std::vector<int> src = {3, 2, 2, 3};
  Solution s;
  std::cout << s.removeElement(src, 3) << std::endl;
}
