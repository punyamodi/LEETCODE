class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        def helper(l, r):
            if l > r:
                return None
            mid = (l + r) // 2
            node = TreeNode(nums[mid])
            node.left = helper(l, mid - 1)
            node.right = helper(mid + 1, r)
            return node
        
        return helper(0, len(nums) - 1)