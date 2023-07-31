#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    string result;
    if (numRows == 2) {
      string result1;
      string result2;
      for (int i = 0; i < s.size(); i++) {
        if ((i % 2) == 0) {
          result1 += s[i];
        } else {
          result2 += s[i];
        }
      }

      return result1 + result2;
    }

    string::size_type size = s.size();
    int group = size / (numRows + numRows - 2);
    int tmp = size % (numRows + numRows - 2);
    int res_size = 0;

    if (tmp == 0) {
      res_size = group * (numRows - 1);
    } else if (tmp <= numRows) {
      res_size = group * (numRows - 1) + 1;
    } else {
      res_size = group * (numRows - 1) + 1 + (tmp - numRows);
    }

    char res[numRows][res_size];
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < res_size; j++) {
        res[i][j] = ' ';
      }
    }

    for (int i = 0; i < size; i++) {
      int n = (i + 1) / (numRows + numRows - 2);
      int m = (i + 1) % (numRows + numRows - 2);

      if (m <= numRows && m > 0) {
        res[m - 1][n * (numRows - 1)] = s[i];
      } else if (m == 0) {
        res[1][(n - 1) * (numRows - 1) + numRows - 1 - 1] = s[i];
      } else {
        res[numRows - (m - numRows + 1)][n * (numRows - 1) + (m - numRows)] =
            s[i];
      }
    }

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < res_size; j++) {
        if (res[i][j] == ' ') {
          continue;
        }
        result += res[i][j];
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  string result = s.convert("PAYPALISHIRING", 3);
  cout << result << endl;
  return 0;
}