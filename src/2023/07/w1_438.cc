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

  vector<int> findAnagrams2(string s, string p) {
    size_t p_size = p.size();
    size_t s_size = s.size();

    if (p_size > s_size) {
      return {};
    }

    vector<int> ans;
    vector<int> s_count(26);
    vector<int> p_count(26);

    for (int i = 0; i < p_size; ++i) {
      ++s_count[s[i] - 'a'];
      ++p_count[p[i] - 'a'];
    }

    if (s_count == p_count) {
      ans.emplace_back(0);
    }

    for (int i = 0; i < s_size - p_size; ++i) {
      --s_count[s[i] - 'a'];
      ++s_count[s[i + p_size] - 'a'];
      if (s_count == p_count) {
        ans.emplace_back(i + 1);
      }
    }

    return ans;
  }

  vector<int> findAnagrams(string s, string p) {
    size_t p_size = p.size();
    size_t s_size = s.size();

    if (p_size > s_size) {
      return {};
    }

    vector<int> ans;
    vector<int> count(26);

    for (int i = 0; i < p_size; ++i) {
      ++count[s[i] - 'a'];
      --count[p[i] - 'a'];
    }

    int differ = 0;
    for (auto c : count) {
      if (c != 0) {
        differ++;
      }
    }

    if (differ == 0) {
      ans.emplace_back(0);
    }

    for (int i = 0; i < s_size - p_size; ++i) {
      if (count[s[i] - 'a'] == 1) {
        --differ;
      } else if (count[s[i] - 'a'] == 0) {
        ++differ;
      }
      --count[s[i] - 'a'];

      if (count[s[i + p_size] - 'a'] == -1) {
        --differ;
      } else if (count[s[i + p_size] - 'a'] == 0) {
        ++differ;
      }
      ++count[s[i + p_size] - 'a'];

      if (differ == 0) {
        ans.emplace_back(i + 1);
      }
    }

    return ans;
  }
};

int main() {
  Solution *solution = new Solution();

  string s = "cbaebabacd";
  string p = "abc";

  vector<int> result = solution->findAnagrams1(s, p);

  for (auto v : result) {
    cout << v << endl;
  }
  return 0;
}
