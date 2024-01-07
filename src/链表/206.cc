/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {

    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *pre = head;
    ListNode *cur = head->next;
    ListNode *n = head->next->next;
    int i = 0;
    while (true) {
      cur->next = pre;
      if (i == 0) {
        pre->next = nullptr;
      }

      pre = cur;
      i++;
      if (n == nullptr) {
        break;
      }
      cur = n;
      n = n->next;
    }

    return cur;
  }
};