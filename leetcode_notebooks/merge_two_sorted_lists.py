# Definition for singly-linked list.
from ast import List
from lib2to3.pgen2.token import OP
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        temp = ListNode(0, None)
        lastNode = temp
        while True:
            # If list1 is empty
            if list1 is None:
                lastNode.next = list2
                break
            # If list2 is empty
            elif list2 is None:
                lastNode.next = list1
                break
            
            if list1.val <= list2.val:
                lastNode.next = list1
                list1 = list1.next
            else:
                lastNode.next = list2
                list2 = list2.next

            lastNode = lastNode.next
        return temp.next


def printer(list: Optional[ListNode]):
    c = list
    while(c.next != None):
        print(c.val)
        c = c.next
    print(c.val)


def main():
    n3 = ListNode(2, None)
    n2 = ListNode(1, n3)
    n1 = ListNode(0, n2)
    m3 = ListNode(9, None)
    m2 = ListNode(8, m3)
    m1 = ListNode(7, m2)
    sol = Solution()
    sol.mergeTwoLists(m1, n1)


if __name__ == "__main__":
    main()
