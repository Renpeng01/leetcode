#include <climits>
#include <iostream>
#include <vector>
class Solution {
public:
  int minSubArrayLen(int target, std::vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums[0] >= target ? 1 : 0;
    }

    int head = 0, tail = 1, sum = nums[0];
    int minLen = INT_MAX;
    while (true) {
      if (sum >= target) {
        for (int i = head; i < tail; i++) {
          if ((sum - nums[i]) >= target) {
            sum -= nums[i];
            head++;
          } else {
            break;
          }
        }

        if ((tail - head) < minLen) {
          minLen = tail - head;
          // std::cout << "head: " << head << " tail: " << tail << std::endl;
        }
      }
      if (tail >= nums.size()) {
        break;
      }
      sum += nums[tail];
      tail++;
    }
    return minLen == INT_MAX ? 0 : minLen;
  }
};

int main() {
  std::vector<int> req = {2, 3, 1, 2, 4, 3};
  Solution s;
  int res = s.minSubArrayLen(7, req);
  std::cout << "res: " << res << std::endl;
}