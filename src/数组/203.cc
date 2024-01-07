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
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *preHead = new ListNode();
    preHead->next = head;
    ListNode *cur = preHead;

    while (head != nullptr) {
      if (head->val == val) {
        if (head->next == nullptr) {
          cur->next = nullptr;
          head->next = nullptr;
          break;
        }
        cur->next = head->next;
        head = head->next;
      } else {
        cur = cur->next;
        head = head->next;
      }
    }
    return preHead->next;
  }
};