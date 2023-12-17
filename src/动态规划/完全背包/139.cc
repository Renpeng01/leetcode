#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i < s.size(); i++) {
      std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
      for (int j = 0; j < i; j++) {
        std::string word = s.substr(j, i - j);
        if (wordSet.find(word) != wordSet.end() && dp[j]) {
          dp[i] = true;
        }
      }
    }
    return dp[s.size()];
  }
};
da