#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode * mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    while (true) {
      int min_val_node_index = -1;
      int min_val = 0x7f7f7f7f;
      bool some_not_null = false;
      for (int i = 0; i < lists.size(); i++) {
        ListNode* ln = lists[i];
        if (ln == NULL) continue;
        some_not_null = true;
        if (ln->val < min_val) {
          min_val = ln->val;
          min_val_node_index = i;
        }
      }
      if (!some_not_null) break;
      cur->next = new ListNode(min_val);
      cur = cur->next;
      lists[min_val_node_index] = lists[min_val_node_index]->next;
    }
    return head->next;
  }
};

int main() {
  ListNode* one = new ListNode(1);
  vector<ListNode*> v;
  v.push_back(one);
  Solution s;
  ListNode* res = s.mergeKLists(v);
  cout << res->val << endl;
  return 0;
}