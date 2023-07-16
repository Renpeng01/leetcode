#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  // 暴力方式  超时
  vector<int> findAnagrams1(string s, string p) {
    size_t p_size = p.length();
    size_t s_size = s.length();

    if (p_size > s_size) {
      return {};
    }

    string sorted_p = p;
    sort(sorted_p.begin(), sorted_p.end());

    vector<int> res;
    for (int i = 0; i <= (s_size - p_size); ++i) {
      string temp = s.substr(i, p_size);
      sort(temp.begin(), temp.end());
      if (sorted_p == temp) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() {
  Solution *solution = new Solution();

  string s = "cbaebabacd";
  string p = "abc";

  vector<int> result = solution->findAnagrams(s, p);

  for (auto v : result) {
    cout << v << endl;
  }
  return 0;
}
