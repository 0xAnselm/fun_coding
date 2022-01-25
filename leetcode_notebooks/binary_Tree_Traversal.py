# In-order, LNR
# Recursively traverse the current node's left subtree.
# Visit the current node (in the figure: position green).
# Recursively traverse the current node's right subtree.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def inorderTraversal(self, root) -> list[int]:
        self.l = []
        self._preOrder(root)
        return self.l

    def _inOrder(self, root):        
        if root:
            self._inOrderTraversal(root.left)
            self.l.append(root.val)
            self._inOrderTraversal(root.right)
    
    def _preOrder(self, root):
        if root:
            self.l.append(root.val)
            self._preOrder(root.left)
            self._preOrder(root.right)
    
    def _postOrder(self, root):
        if root:
            self._postOrder(root.left)
            self._postOrder(root.right)
            self.l.append(root.val)
def main():
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    sol = Solution()
    res = sol.inorderTraversal(root)
    print(res)

if __name__ == "__main__":
    main()