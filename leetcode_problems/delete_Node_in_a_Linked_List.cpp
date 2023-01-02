#include <iostream>
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    // ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        std::cout << "Test\n" << node->next->val;
    }
};

int main() {
    Solution sol;
    ListNode l2{2, NULL};    
    ListNode l1{1, &l2};
    sol.deleteNode(&l1);
    return 0;
}