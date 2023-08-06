#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int result = 0;
    if (nums.size() <= 3) {
      for (auto v : nums) {
        result += v;
      }
      return result;
    }

    int minDiff = INT_MAX;
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int pb = i + 1;
      int pc = nums.size() - 1;

      while (pb < pc) {
        int sum = nums[i] + nums[pb] + nums[pc];
        int diff = sum - target;

        if (diff == 0) {
          return sum;
        }
        if (abs(diff) < minDiff) {
          res = sum;
          minDiff = abs(diff);
        }

        if (diff > 0) {
          --pc;
        } else {
          ++pb;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> vec = {4, 0, 5, -5, 3, 3, 0, -4, -5};
  int res = s.threeSumClosest(vec, -2);

  cout << "res: " << res << endl;
  return 0;
}