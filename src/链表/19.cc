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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummyHead = new ListNode();
    dummyHead->next = head;
    ListNode *fast = head;
    ListNode *slow = dummyHead;

    for (int i = 0; i < n; i++) {
      if (fast == nullptr) {
        return head;
      }
      fast = fast->next;
    }

    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    slow->next = slow->next->next;
    ListNode *res = dummyHead->next;

    //  注意，合理需要delete释放空间
    delete dummyHead;
    return res;
  }
};