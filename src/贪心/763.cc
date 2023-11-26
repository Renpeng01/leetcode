#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void printArr(int arr[27]);

class Solution {
public:
  std::vector<int> partitionLabels(std::string s) {
    int a[27] = {0};
    for (int i = 0; i < s.size(); i++) {
      a[s[i] - 'a'] = i;
    }

    std::vector<int> res;

    int begin = 0;
    int end = 0;
    for (int i = 0; i < s.size(); i++) {
      end = std::max(end, a[s[i] - 'a']);
      if (i == end) {
        res.push_back(end - begin + 1);
        begin = i + 1;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  std::string test1 = "ababcbacadefegdehijhklij";
  std::vector<int> res = s.partitionLabels(test1);

  for (auto e : res) {
    std::cout << e << std::endl;
  }
}

void printArr(int arr[27]) {
  for (int i = 0; i < 27; i++) {
    std::cout << "ind: " << i << " " << arr[i] << std::endl;
  }
}