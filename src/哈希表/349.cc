#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection2(vector<int> &nums1, vector<int> &nums2) {

    // 可以换成set
    std::unordered_map<int, bool> nums1_map;
    std::unordered_map<int, bool> nums2_map;
    std::vector<int> res;

    for (int i = 0; i < nums1.size(); i++) {
      nums1_map[nums1[i]] = true;
    }

    for (int i = 0; i < nums2.size(); i++) {
      nums2_map[nums2[i]] = true;
    }

    for (std::unordered_map<int, bool>::iterator it_1 = nums1_map.begin();
         it_1 != nums1_map.end(); it_1++) {
      if (nums2_map.find(it_1->first) != nums2_map.end()) {
        res.push_back(it_1->first);
      }
    }
    return res;
  }
};