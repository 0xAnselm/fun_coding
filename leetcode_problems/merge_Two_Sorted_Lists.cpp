#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* lastNode;
        ListNode* temp = new ListNode();
        lastNode = temp;
        while (true) {
            if (list1 == NULL) {
                lastNode->next = list2;
                break;
            } else if (list2 == NULL) {
                lastNode->next = list1;
                break;
            }    
            if (list1->val <= list2->val) {
                lastNode->next = list1;
                list1 = list1->next;
            } else {
                lastNode->next = list2;
                list2 = list2->next;
            }

            lastNode = lastNode->next;
        }
        return temp->next;
    }   
};