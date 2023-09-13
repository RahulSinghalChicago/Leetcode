'''
Use 3 lists of lists for left, middle and right of tree.
Level order traversal storing a tuple of (position, node) in Q
position is computed as parent-1 and parent+1
pop from left side of Q and append to right side of list for each column
the column is selected using the position, negative positions from the left list
positive positions in the right light
indexes in the negative list need to turned postive to store
a check against the size of a list is needed before accessing to extend if needed
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        if not root:
            return []

        lft = []
        ctr = []
        rht = []
        
        Q = deque([(0, root)])

        while Q:

            pos, node = Q.popleft()
            if pos == 0:
                ctr.append(node.val)
            elif pos > 0:
                if len(rht) < pos:
                    rht.append([])
                rht[pos-1].append(node.val)
            else:
                if len(lft) < abs(pos):
                    lft.append([])
                lft[abs(pos)-1].append(node.val)
            if node.left:
                Q.append((pos-1, node.left))
            if node.right:
                Q.append((pos+1, node.right))

        return lft[::-1] + [ctr] + rht