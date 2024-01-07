#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList {
public:
  MyLinkedList() : head(new ListNode()), tail(head), len(0) {}

  void printNodesVal() {
    std::cout << "len: " << len << std::endl;
    ListNode *cur = head->next;
    while (cur != nullptr) {
      std::cout << " " << cur->val;
      cur = cur->next;
    }
    std::cout << std::endl;
  }

  int get(int index) {
    if (index >= len || index < 0) {
      return -1;
    }
    ListNode *cur = head;
    for (int i = 0; i <= index; i++) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    ListNode *node = new ListNode(val);
    node->next = head->next;
    head->next = node;
    if (len == 0) {
      tail = node;
    }
    len++;
  }

  void addAtTail(int val) {
    ListNode *node = new ListNode(val);
    tail->next = node;
    tail = node;
    len++;
  }

  void addAtIndex(int index, int val) {
    if (index > len) {
      return;
    }
    if (index == 0) {
      addAtHead(val);
      return;
    }

    if (index >= len) {
      addAtTail(val);
      return;
    }

    ListNode *pre = head;
    for (int i = 0; i < index; i++) {
      pre = pre->next;
    }

    ListNode *node = new ListNode(val);
    node->next = pre->next;
    pre->next = node;
    len++;
  }

  void deleteAtIndex(int index) {
    if (index >= len || len == 0) {
      return;
    }
    if (index == 0) {
      head->next = head->next->next;
      len--;
      if (head->next == nullptr) {
        tail = nullptr;
      }
      return;
    }
    ListNode *cur = head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    cur->next = cur->next->next;
    if (index == len - 1) {
      tail = cur;
    }
    len--;
  }

private:
  ListNode *head;
  ListNode *tail;
  int len;
};

int main() {
  MyLinkedList list;
  // list.addAtHead(1);
  // list.addAtTail(3);

  // list.addAtIndex(1, 2);
  // list.printNodesVal();
  // int get1 = list.get(1);
  // std::cout << "get(1) : " << get1 << std::endl;

  // list.deleteAtIndex(1);
  // get1 = list.get(1);
  // std::cout << "get(1): " << get1 << std::endl;

  // list.printNodesVal();

  list.addAtHead(7);
  list.addAtHead(2);
  list.addAtHead(1);
  list.addAtIndex(3, 0);
  // 1270
  list.printNodesVal();

  list.deleteAtIndex(2);
  // 120
  list.printNodesVal();
}