# Definition for singly-linked list.
from turtle import right
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __str__(self) -> str:
        return self.val
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
    def __str__(self) -> str:
        return self.val
class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        self.pathFound = False
        self.startingNodes = []
        def getAllStartingNodes(head, root):
            if(head == None or root == None):
                return
            if(head.val == root.val):
                self.startingNodes.append(root)
            
            getAllStartingNodes(head, root.left)
            getAllStartingNodes(head, root.right)

        def checkForPath(head: ListNode, root: TreeNode):
            if head == None:  return True
            if root == None: return False

            if(head.val == root.val):
                return (checkForPath(head.next, root.left)
                    or checkForPath(head.next, root.right))

            return False
        
        self.startingNodes.clear()
        getAllStartingNodes(head, root)
        for node in self.startingNodes:
            if checkForPath(head, node): return True
        
        return False
                


root = TreeNode(1)
root.left = TreeNode(4)
root.left.right = TreeNode(2)
root.left.right.left = TreeNode(1)

root.right=TreeNode(4)
root.right.left = TreeNode(2)
root.right.left.left = TreeNode(6)
root.right.left.right = TreeNode(8)
root.right.left.right.left = TreeNode(1)
root.right.left.right.right = TreeNode(3)

head = ListNode(1)
head.next = ListNode(4)
head.next.next = ListNode(2)
head.next.next.next = ListNode(6)

sol = Solution()
print(sol.isSubPath(head, root))
