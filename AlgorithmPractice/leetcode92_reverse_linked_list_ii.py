# Definition for singly-linked list.
class ListNode:
  def __init__(self, x):
    self.val = x
    self.next = None
  
  def show_all(self):
    node = self
    while node is not None:
      print(node.val, end=' ')
      node = node.next
    print()

class Solution:
  def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
    ret = ListNode(0)
    ret.next = head
    last = ret

    node_m = None
    node_n = None
    node_m_last = None
    node_n_next = None
    i = 1
    node_i = ret.next
    while i <= n and node_i is not None:
      ori_next = node_i.next

      if m <= i <= n:
        node_i.next = last

        if i == m:
          node_m = node_i
          node_m_last = last
        if i == n:
          node_n = node_i
          node_n_next = ori_next

      last = node_i
      node_i = ori_next
      i += 1
    
    node_m.next = node_n_next
    node_m_last.next = node_n
    return ret.next


if __name__ == "__main__":
  s = Solution()
  n1 = ListNode(1)
  n2 = ListNode(2)
  n3 = ListNode(3)
  n4 = ListNode(4)
  n5 = ListNode(5)
  n1.next = n2
  n2.next = n3
  n3.next = n4
  n4.next = n5
  n1.show_all()

  n = s.reverseBetween(n1, 1, 5)
  n.show_all()
