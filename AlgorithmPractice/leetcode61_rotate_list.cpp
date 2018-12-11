#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode * rotateRight(ListNode* head, int k) {
    if (head == NULL) return NULL;
    ListNode* node = head;
    int len = 1;
    while (node->next != NULL) {
      node = node->next;
      len++;
    }
    ListNode* tail = node;
    int mod = k % len;
    if (mod == 0) return head;
    node = head;
    for (int i = 0; i < len; i++) {
      if (mod == len - i - 1) {
        tail->next = head;
        ListNode* ret = node->next;
        node->next = NULL;
        return ret;
      }
      node = node->next;
    }
  }
};

//int main() {
//  ListNode* n1 = new ListNode(1);
//  ListNode* n2 = new ListNode(2);
//  ListNode* n3 = new ListNode(3);
//  ListNode* n4 = new ListNode(4);
//  ListNode* n5 = new ListNode(5);
//  n1->next = n2;
//  n2->next = n3;
//  n3->next = n4;
//  n4->next = n5;
//  Solution s;
//
//  ListNode* node = s.rotateRight(n1, 6);
//  while (node != NULL) {
//    cout << node->val << " ";
//    node = node->next;
//  }
//  cout << endl;
//
//  return 0;
//}