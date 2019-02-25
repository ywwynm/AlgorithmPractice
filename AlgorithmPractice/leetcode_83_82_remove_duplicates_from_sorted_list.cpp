#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  void printNodes(ListNode* head) {
    ListNode *cur = head;
    while (cur != NULL) {
      cout << cur->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }

  ListNode * deleteDuplicates(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode *cur = head;
    while (cur->next != NULL) {
      if (cur->val == cur->next->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }

  ListNode* deleteDuplicates2(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* retHead = new ListNode(0);
    ListNode* last = retHead;
    retHead->next = head;
    ListNode* cur = head;
    bool shouldDeleteLast = false;
    while (cur->next != NULL) {
      if (cur->val == cur->next->val) {
        shouldDeleteLast = true;
        cur->next = cur->next->next;
      } else {
        if (shouldDeleteLast) {
          last->next = cur->next;
        } else {
          last = cur;
        }
        shouldDeleteLast = false;
        cur = cur->next;
      }
    }
    return retHead->next;
  }
};

int main() {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(2);
  ListNode *n4 = new ListNode(3);
  ListNode *n5 = new ListNode(3);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Solution s;
  s.printNodes(n1);

  ListNode* newHead = s.deleteDuplicates2(n1);
  s.printNodes(newHead);
  return 0;
}