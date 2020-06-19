class TreeNode:
  def __init__(self, x):
    self.val = x
    self.left = None
    self.right = None


class Solution:
  def inorderTraversal(self, root: TreeNode) -> List[int]:
    ret = []

    def traversal(node: TreeNode):
      if node is not None:
        ret.append(node.val)
        traversal(node.left)
        traversal(node.right)
    
    traversal(root)

    return ret


if __name__ == "__main__":
  s = Solution()
