#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int left = 0;
    int right = s.size() - 1;
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