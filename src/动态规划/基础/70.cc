#include <iostream>
#include <vector>

class Solution {
public:
  // ·本质是fib
  int climbStairs(int n) {
    int p1 = 1;
    int p2 = 2;
    int sum = 0;

    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }

    for (int i = 3; i <= n; i++) {
      sum = p1 + p2;
      p1 = p2;
      p2 = sum;
    }

    return sum;
  }
};