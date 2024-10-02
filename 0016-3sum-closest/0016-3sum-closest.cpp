class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        // Initialize the sum with the sum of the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        // Iterate over the array
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = nums.size() - 1;  // Two pointers
            
            // Use two-pointer approach
            while (j < k) {
                int sum1 = nums[i] + nums[j] + nums[k];
                
                // Check if the current sum is closer to the target than the previous closest
                if (abs(sum1 - target) < abs(closestSum - target)) {
                    closestSum = sum1;
                }
                
                // Move pointers based on the comparison between sum1 and target
                if (sum1 < target) {
                    j++;  // Move the left pointer to the right
                } 
                else if (sum1 > target) {
                    k--;  // Move the right pointer to the left
                }
                else {
                    // If the sum is exactly equal to the target, return it immediately
                    return sum1;
                }
            }
        }
        return closestSum;
    }
};
