class Solution:
    def removeNthFromEnd(self, head: ListNode | None, n: int) -> ListNode | None:
        if not head:
            return None

        leading = head
        trailing = head

        count = 0
        while leading and count != n:
            leading = leading.next
            count += 1

        if not leading:
            return head.next

        while leading.next:
            trailing = trailing.next
            leading = leading.next

        temp = trailing.next
        trailing.next = temp.next

        return head