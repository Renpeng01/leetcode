#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int len = pow(n, 2);
    vector<vector<int>> ans = vector<vector<int>>(len, vector<int>(len, 0));
    for (int i = len - 1; i > 0; i -= 2) {
      for (int j = 0; j < i; j++) {
        ans[i][i + j] = 1;
        ans[i][k] = 1;
      }
    }

    return ans;
  }
};