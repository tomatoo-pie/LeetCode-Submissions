# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        a = node

        while(a.next.next):
            a.val = a.next.val
            a = a.next
        
        a.val = a.next.val
        a.next = None
        