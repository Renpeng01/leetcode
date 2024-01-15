
#include <string>

using namespace std;

class Solution {
public:
  string reverseStr(string s, int k) {
    int group = 0;
    if (s.size() <= k) {
      reverseSubStr(s, 0, s.size() - 1);
      return s;
    }
    for (int i = 0; i < s.size(); i++) {
      if ((i / k % 2) == 0) {
        group++;
        if (group == k) {
          reverseSubStr(s, i - k + 1, i);
          group = 0;
          continue;
        }
        if (i == (s.size() - 1)) {
          reverseSubStr(s, s.size() - 1 - group + 1, s.size() - 1);
          continue;
        }
      }
    }
    return s;
  }

  void reverseSubStr(string &s, int start, int end) {
    int left = start;
    int right = end;
    char tmp;
    while (left < right) {
      tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }
  }
};