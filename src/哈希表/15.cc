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

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int m = j + 1; m < n; m++) {
          mCode = code(nums[i], nums[j], nums[m]);
          if ((nums[i] + nums[j] + nums[m]) == 0 &&
              map.find(mCode) == map.end()) {
            res.push_back({nums[i], nums[j], nums[m]});
            map[mCode] = true;
            continue;
          }
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