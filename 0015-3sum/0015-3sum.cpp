class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the array
        vector<vector<int>> ans;  // Result container

        // Iterate over the array
        for (int i = 0; i < nums.size() - 2; i++) {
            // Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = nums.size() - 1;  // Two pointers

            // Use two-pointer approach
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicates for the second and third numbers
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    while (j < k && nums[k] == nums[k - 1]) k--;

                    // Move both pointers inward
                    j++;
                    k--;
                } 
                else if (sum < 0) {
                    j++;  // Move the left pointer to the right
                } 
                else {
                    k--;  // Move the right pointer to the left
                }
            }
        }

        return ans;
    }
};
