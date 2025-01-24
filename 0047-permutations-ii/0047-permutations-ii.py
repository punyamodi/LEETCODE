class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.ans = []
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        def backtrack(subset):
            if len(subset) == len(nums):
                self.ans.append(subset.copy())
                return
            used_at_this_level = set()
            for i in range(len(nums)):
                # used.add(nums[i])
                if freq[nums[i]] == 0 or nums[i] in used_at_this_level:
                    continue
                if freq[nums[i]] > 0:
                    freq[nums[i]] -= 1
                    subset.append(nums[i])
                    backtrack(subset)
                    used_at_this_level.add(nums[i])
                    subset.pop()
                    freq[nums[i]] += 1
                # used.remove(nums[i])
        backtrack([])
        return self.ans