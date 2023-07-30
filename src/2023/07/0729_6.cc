#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
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

    string result;
    for (int i = 0; i < size; i++) {
      int n = (i + 1) / (numRows + numRows - 2);
      int m = (i + 1) % (numRows + numRows - 2);

      // cout << "m: " << m << " numRows:" << numRows << " (numRows + numRows
      // -2)"
      //      << (numRows + numRows - 2) << " i: " << (i + 1) << " s[i]: " <<
      //      s[i]
      //      << endl;
      if (m <= numRows && m > 0) {
        res[m - 1][n * (numRows - 1)] = s[i];
      } else {
        cout << "i: " << m + 1 << " j:" << (n * (numRows - 1) + (m - numRows))
             << " s: " << s[i] << endl;
        res[m + 1][n * (numRows - 1) + (m - numRows)] = s[i];
      }
    }

    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < res_size; j++) {
        cout << res[i][j];
      }
      cout << endl;
    }
    return result;
    // return "";
  }
};

int main() {
  Solution s;
  s.convert("PAYPALISHIRING", 4);
  return 0;
}