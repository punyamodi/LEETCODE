class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # Start with the last row of the triangle as our DP base
        dp = triangle[-1]
        
        # Iterate from the second-to-last row up to the top
        for row in range(len(triangle) - 2, -1, -1):
            for col in range(len(triangle[row])):
                # The minimum path for current node is its value + 
                # the minimum of the two options below it
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1])
        
        # The top element now contains the minimum path sum
        return dp[0]