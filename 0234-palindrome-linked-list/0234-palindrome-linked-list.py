# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode | None) -> bool:
        if not head or not head.next:
            return True
            
        fast = head
        slow = head
        prev = None

        while fast and fast.next:
            fast = fast.next.next
            prev = slow
            slow = slow.next

        curr = slow
        prevslow = None

        prev.next = None 

        while curr:
            nxt = curr.next
            curr.next = prevslow
            prevslow = curr
            curr = nxt
        
        slow = prevslow
        curr = slow
        curr1 = head

        while curr and curr1:
            if curr.val != curr1.val:
                return False
            curr = curr.next
            curr1 = curr1.next
            
        return True