#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    unordered_map<string, bool> map;
    vector<vector<int>> res;
    string mCode = "";
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        break;
      }
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {

        cout << "i:" << i << " left: " << left << " right: " << right << endl;
        cout << "sum: " << nums[left] + nums[right] + nums[i]
             << "vi:" << nums[i] << " vleft: " << nums[left]
             << " vright: " << nums[right] << endl;
        if ((nums[left] + nums[right] + nums[i]) > 0) {
          right--;
        } else if ((nums[left] + nums[right] + nums[i]) < 0) {
          left++;
        } else {
          cout << "11111" << endl;
          if (map.find(mCode) == map.end()) {
            res.push_back(vector<int>{nums[i], nums[left], nums[right]});
            map[mCode] = true;
          }
          right--;
          left++;
        }
      }
    }
    return res;
  }

  string code(int a, int b, int c) {
    string code = "";
    vector<int> s = {a, b, c};
    sort(s.begin(), s.end());
    for (auto v : s) {
      code = code + to_string(v) + "_";
    }

    cout << "code: " << code << endl;
    return code;
  }
};