#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode * reverseKGroup(ListNode* head, int k) {
    if (k == 1) return head;
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
  ListNode* ln = s.reverseKGroup(ln1, 2);

  while (ln != NULL) {
    cout << ln->val << endl;
    ln = ln->next;
  }

  return 0;
}