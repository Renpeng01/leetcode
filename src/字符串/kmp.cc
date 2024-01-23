#include <string>

using namespace std;

void getNext(int *next, const string &s) {
  int j = 0;
  next[0] = 0;

  for (int i = 1; i < s.size(); i++) {
    while (j > 0 && s[j] != s[i]) {
      j = next[j - 1];
    }

    if (s[j] == s[i]) {
      j++;
    }
    next[i] = j;
  }
}