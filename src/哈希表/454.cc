#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> map;
    for (int a : nums1) {
      for (int b : nums2) {
        map[a + b]++;
      }
    }

    print(map);
    int ans = 0;
    for (int c : nums3) {
      for (int d : nums4) {
        if (map.count(-c - d)) {
          ans += map[-c - d];
        }
      }
    }
    return ans;
  }

  int fourSumCount1(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                    vector<int> &nums4) {
    unordered_map<int, int> map;

    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        map[nums1[i] + nums2[j]]++;
      }
    }

    int res = 0;
    for (int i = 0; i < nums3.size(); i++) {
      for (int j = 0; j < nums4.size(); j++) {
        if (map.find(-nums3[i] - nums4[j]) != map.end()) {
          res += map[-nums3[i] - nums4[j]];
        }
      }
    }
    return res;
  }

  void print(unordered_map<int, int> map) {
    for (auto it = map.begin(); it != map.end(); it++) {
      cout << it->first << " " << it->second << endl;
    }
  }
};