#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

  void reverse2(ListNode* head, ListNode* node, ListNode* swap) {
    if (node->next == NULL) return;
    ListNode* a = node, *b = node->next;
    swap = b->next;
    b->next = a;
    a->next = swap;
    head->next = b;
  }

  void reverse(ListNode* head, ListNode* node, ListNode* swap, int num) {
    // node到node后num个node进行颠倒(包括node), head->next = node
    for (int i = 1; i <= num - 1; i++) {
      int cur = 0;
      ListNode* realHead = head;
      while (cur < num - i) {
        reverse2(realHead, node, swap);
        cur++;
        realHead = head->next;
      }
    }
  }

  ListNode * reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    ListNode* newHead = new ListNode(0), *swap = NULL, *cur = head, *circleBeforeHead = newHead;
    newHead->next = head;
    while (cur != NULL) {
      ListNode* tmp = cur;
      for (int i = 0; i < k - 1; i++) {
        if (tmp->next == NULL) {
          break; // 长度不够
        }
        tmp = tmp->next;
      }

      reverse(circleBeforeHead, cur, swap, k);

      tmp = circleBeforeHead->next;
      for (int i = 0; i < k - 1; i++) {
        tmp = tmp->next;
      }
      circleBeforeHead = tmp;

      if (circleBeforeHead != NULL) {
        cur = circleBeforeHead->next;
      }
      else break;
    }
    return newHead->next;
  } 
};

int main() {
  ListNode* ln1 = new ListNode(1);
  ListNode* ln2 = new ListNode(2);
  ListNode* ln3 = new ListNode(3);
  ListNode* ln4 = new ListNode(4);
  ListNode* ln5 = new ListNode(5);
  ln1->next = ln2;
  ln2->next = ln3;
  ln3->next = ln4;
  ln4->next = ln5;
  Solution s;
  ListNode* ln = s.reverseKGroup(ln1, 3);

  while (ln != NULL) {
    cout << ln->val << endl;
    ln = ln->next;
  }

  return 0;
}