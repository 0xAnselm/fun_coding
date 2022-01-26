# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def _inOrder(self, root):
        if root:
            self._inOrder(root.left)
            self.l.append(root.val)
            self._inOrder(root.right)

    def getAllElements(self, root1, root2) -> list[int]:
        self.l = []
        self._inOrder(root1)
        self._inOrder(root2)
        return sorted(self.l)


def main():
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root2 = TreeNode(1)
    root2.left = TreeNode(0)
    root2.right = TreeNode(3)
    
    sol = Solution()
    res = sol.getAllElements(root, root2)
    print(res)


if __name__ == "__main__":
    main()
