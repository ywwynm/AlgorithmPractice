#include <iostream>
#include <vector>
#include <queue>

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

  struct Cmp {
    bool operator() (ListNode* const ln1, ListNode* const ln2) {
      return ln1->val > ln2->val;
    }
  };

  /*
    Use a priority queue to reduce time complexity
  */
  ListNode* mergeKListsPriorityQ(vector<ListNode*>& lists) {
    ListNode* head = new ListNode(0);
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for (auto node : lists) if (node != NULL) { 
      pq.push(node); 
    }
    ListNode* cur = head;
    while (!pq.empty()) {
      ListNode* ln = pq.top(); pq.pop();
      cur->next = ln;
      cur = cur->next;
      if (ln->next) pq.push(ln->next);
    }
    return head->next;
  }
};

int main() {
  ListNode* ln1 = new ListNode(1);
  ListNode* ln2 = new ListNode(5);
  ln1->next = ln2;

  ListNode* ln3 = new ListNode(2);
  ListNode* ln4 = new ListNode(3);
  ln3->next = ln4;

  vector<ListNode*> v;
  v.push_back(ln1);
  v.push_back(ln3);

  Solution s;
  ListNode* res = s.mergeKListsPriorityQ(v);

  while (res != NULL) {
    cout << res->val << endl;
    res = res->next;
  }

  return 0;
}