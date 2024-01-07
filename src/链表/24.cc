
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *pre = head;
    ListNode *cur = head->next;

    ListNode *tempPre;
    ListNode *tempCur;

    bool isCountine = false;

    ListNode *dummayHead = new ListNode(0, head);
    ListNode *mHead = dummayHead;

    while (true) {
      if (cur->next != nullptr && cur->next->next != nullptr) {
        tempPre = cur->next;
        tempCur = cur->next->next;
        isCountine = true;
      } else {
        isCountine = false;
      }

      pre->next = cur->next;
      cur->next = pre;
      dummayHead->next = cur;

      if (!isCountine) {
        break;
      }

      dummayHead = pre;
      pre = tempPre;
      cur = tempCur;
    }
    return mHead->next;
  }
};