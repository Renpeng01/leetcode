/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// 问题1：为什么一定会相遇，快指针有可能跳过慢指针吗
// 答案：当慢指针进入环时，快指针已经在环内，相对于慢指针，指针以每次多一步的速度靠近慢指针，所以一定会相遇

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {}
};