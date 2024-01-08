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

// 如何找到环的入口
// 从起点到入口位置的距离为x，入口到相遇位置的长度为y， 从相遇位置到入口为z
// slow x + y
// fast x + y + n * (y + z)
// 2 * slow = fast
// 2(x + y) = x + y + n(y + z)
// x = n(y + z) - y (n >= 1)
// x = (n-1) (y+1) + z;
// x = z;

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {

    if (!head) {
      return nullptr;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *match;

    while (fast) {
      slow = slow->next;
      if (!fast->next) {
        return nullptr;
      }
      fast = fast->next->next;
      if (slow == fast) {
        match = slow;
        break;
      }
    }

    if (!fast) {
      return nullptr;
    }

    while (match != head) {
      match = match->next;
      head = head->next;
    }
    return match;
  }
};