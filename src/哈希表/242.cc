#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    std::unordered_map<char, int> s_umap;
    std::unordered_map<char, int> t_umap;

    for (int i = 0; i < s.size(); i++) {
      s_umap[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++) {
      t_umap[t[i]]++;
    }
    if (s_umap.size() != t_umap.size()) {
      return false;
    }

    for (std::unordered_map<char, int>::iterator it = s_umap.begin();
         it != s_umap.end(); ++it) {

      auto t_umap_iterator = t_umap.find(it->first);
      if (t_umap_iterator == t_umap.end()) {
        return false;
      }
      if (t_umap_iterator->second != it->second) {
        return false;
      }
    }
    return true;
  }
};