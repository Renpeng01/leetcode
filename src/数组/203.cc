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
    while (head && head->val == val) {
      head = head->next;
    }
    ListNode *preHead = new ListNode();
    ListNode *tag = new ListNode();
    preHead->next = head;
    tag->next = head;

    while (head != nullptr) {
      if (head->val == val) {
        if (head->next == nullptr) {
          preHead->next = nullptr;
          head->next = nullptr;
          break;
        }
        preHead->next = head->next;
        head = head->next;
      } else {
        preHead = preHead->next;
        head = head->next;
      }
    }
    return tag->next;
  }
};