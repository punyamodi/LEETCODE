class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        row, column = len(matrix), len(matrix[0])
        maxArea = 0
        heights = [0]*column
        for r in range(row):
            for c in range(column):
                if matrix[r][c] == '1':
                    heights[c] += 1
                else:
                    heights[c] = 0
            maxArea = max(maxArea,self.LargestRetangleArea(heights))
        return maxArea
    def LargestRetangleArea(self,heights):
        stack = []
        heights = heights + [0]
        n = len(heights)
        area = 0
        for i in range(n):
            stack_idx = i
            height = heights[i]
            while stack and stack[-1][0] >= height:
                stack_height, stack_idx = stack.pop()
                width = i - stack_idx
                area = max(area,(stack_height*width))
            stack.append((height,stack_idx))
        return area