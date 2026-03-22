class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        # 1. Base case: empty tree
        if not root:
            return 0
        
        # 2. If left child is missing, we must go right
        if not root.left:
            return 1 + self.minDepth(root.right)
            
        # 3. If right child is missing, we must go left
        if not root.right:
            return 1 + self.minDepth(root.left)
        
        # 4. If both exist, take the minimum of both paths
        return 1 + min(self.minDepth(root.left), self.minDepth(root.right))