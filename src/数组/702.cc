#include <iostream>
#include <vector>
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class ArrayReader {
public:
  int get(int index) const {
    if (index >= vec.size()) {
      return 2147483647;
    }
    return vec[index];
  }

  void push(int v) { vec.push_back(v); }

public:
  std::vector<int> vec;
};

class Solution {
public:
  // 使用[x,y)左闭右开的方式表示范围
  int search(const ArrayReader &reader, int target) {
    int size = getLen(reader);
    std::cout << "getLen: " << size << std::endl;
    if (size == 0) {
      return -1;
    }
    if (size == 1) {
      return reader.get(0) == target ? 0 : -1;
    }

    int left = 0, right = size, middle = 0;
    while (left < right) {
      middle = left + (right - left) / 2;
      if (reader.get(middle) > target) {
        right = middle;
      } else if (reader.get(middle) < target) {
        left = middle + 1;
      } else {
        return middle;
      }
    }
    return -1;
  }

private:
  int getLen(const ArrayReader &reader) {
    int i = 0;
    while (true) {
      if (reader.get(i) == 2147483647) {
        break;
      }
      i++;
    }
    return i;
  }
};

int main() {
  std::vector<int> inputs = {-1, 0, 3, 5, 9, 12};
  ArrayReader *r = new ArrayReader;
  for (int i = 0; i < inputs.size(); i++) {
    r->push(inputs[i]);
  }

  Solution s;
  int res = s.search(*r, 5);
  std::cout << "res: " << res << std::endl;
}