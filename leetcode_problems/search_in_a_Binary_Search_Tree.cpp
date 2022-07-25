#include <iostream>
/* Definition for a binary tree node. */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return NULL;

        if (root->val == val)
        {
            // std::cout << "Found " << root->val << root->left->val << root->right->val << "\n";
            return root;
        }
        else if (val < root->val && root->left != nullptr)
        {
            return searchBST(root->left, val);
        }
        else
        {
            return searchBST(root->right, val);
        }
        return nullptr;
    }
};

void treePinter(TreeNode *root)
{
    if (root != nullptr)
    {
        std::cout << root->val << " ";
        return treePinter(root->left), treePinter(root->right);
    }
}

int main()
{
    TreeNode treeLL(1);
    TreeNode treeLR(3);
    TreeNode treeL(2, &treeLL, &treeLR);
    TreeNode treeR(7);
    TreeNode tree(4, &treeL, &treeR);
    TreeNode *root = &tree;
    Solution sol;
    TreeNode *result = sol.searchBST(root, 2);
    treePinter(sol.searchBST(root, 2));
    return 0;
}