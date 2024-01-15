#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    int left = 0;
    int right = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {

      if (nums[i] > target && nums[i] > 0 && target > 0) {
        break;
      }
      for (int j = i + 1; i < nums.size(); j++) {
        left = j + 1;
        right = nums.size() - 1;
        while (left < right) {
          if ((nums[i] + nums[j] + nums[left] + nums[right]) == target) {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});
            left++;
            right--;
          } else if ((nums[i] + nums[j] + nums[left] + nums[right]) > target) {
            right--;
          } else {
            left++;
          }
        }
      }
    }
    return res;
  }
};