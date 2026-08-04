# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current =  head
        previous = None
        next_node = None

        while current is not None:
            next_node = current.next ## remeber next on the list
            current.next = previous ## reverse arrow direction
            previous = current ### update our previous to next ListNode
            current = next_node    ## update our current cycle

        return previous

        