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
    if (node == NULL) {
      return;
    }
    if (node->next == NULL) {
      return;
    }
    ListNode* a = node, *b = node->next;
    swap = b->next;
    b->next = a;
    a->next = swap;
    head->next = b;
  }

  // 0 1 2 3 4, head = 0, node = 1, num = 4
  void reverse(ListNode* head, ListNode* node, ListNode* swap, int num) {
    // node到node后num个node进行颠倒(包括node), head->next = node
    for (int i = 1; i <= num - 1; i++) {
      int cur = 0;
      ListNode* realHead = head;
      while (cur < num - i) {
        reverse2(realHead, realHead->next, swap);
        cur++;
        realHead = head->next;
      }
    }
  }

  void showList(ListNode* head) {
    ListNode* cur = head;
    while (cur != NULL) {
      cout << cur->val << " ";
      cur = cur->next;
    }
    cout << endl;
  }

  ListNode * reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
    ListNode* newHead = new ListNode(0), *swap = NULL, *circleHead = head, *circleBeforeHead = newHead;
    newHead->next = head;
    ListNode* tmp;
    while (circleHead != NULL) {
      tmp = circleHead;
      for (int i = 0; i < k - 1; i++) {
        if (tmp->next == NULL) {
          break; // 长度不够
        }
        tmp = tmp->next;
      }

      reverse(circleBeforeHead, circleHead, swap, k);
      showList(circleBeforeHead);

      tmp = circleBeforeHead->next;
      for (int i = 0; i < k - 1; i++) {
        tmp = tmp->next;
      }
      circleBeforeHead = tmp;

      if (circleBeforeHead != NULL) {
        circleHead = circleBeforeHead->next;
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
  ListNode* ln = s.reverseKGroup(ln1, 4);

  s.showList(ln);

  return 0;
}