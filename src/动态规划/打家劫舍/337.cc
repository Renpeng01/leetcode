#include <algorithm>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int rob(TreeNode *root) {
    std::vector<int> res = rubTree(root);
    return std::max(res[0], res[1]);
  }
  std::vector<int> rubTree(TreeNode *node) {
    if (node == nullptr) {
      return {0, 0};
    }

    std::vector<int> left = rubTree(node->left);
    std::vector<int> right = rubTree(node->right);
    int val1 = node->val + left[0] + right[0];
    int val2 = std::max(left[0], left[1]) + std::max(right[0], right[1]);
    return {val2, val1};
  }
};