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

  ListNode * partition(ListNode* head, int x) {
    ListNode* ret = new ListNode(0);
    ret->next = head;
    ListNode *cur = head, *last = ret;
    while (cur != NULL) {
      if (cur->val >= x) { // 移动到第一个小于x的node前
        ListNode* tmp = cur;
        do {
          if (tmp->next != NULL && tmp->next->val < x) {
            last->next = tmp->next;
            tmp->next = tmp->next->next;
            last->next->next = cur;
            break;
          }
          tmp = tmp->next;
        } while (tmp != NULL && tmp->val >= x);
        if (tmp == NULL) break;
      } else {
        cur = cur->next;
      }
      last = last->next;
    }
    return ret->next;
  }
};

int main() {
  ListNode *n1 = new ListNode(1);
  ListNode *n2 = new ListNode(4);
  ListNode *n3 = new ListNode(3);
  ListNode *n4 = new ListNode(2);
  ListNode *n5 = new ListNode(5);
  ListNode *n6 = new ListNode(2);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  Solution s;
  s.printNodes(n1);

  ListNode* newHead = s.partition(n1, 3);
  s.printNodes(newHead);
  return 0;
}