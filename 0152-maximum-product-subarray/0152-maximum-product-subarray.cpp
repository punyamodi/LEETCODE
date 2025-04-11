class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0; // Handle empty array case
        }

        int max_so_far = nums[0]; // Initialize max_so_far with the first element
        int min_so_far = nums[0]; // Initialize min_so_far with the first element
        int result = nums[0];     // Initialize result with the first element

        for (int i = 1; i < nums.size(); ++i) {
            int current = nums[i];

            // Calculate the new max and min products considering the current element
            int temp_max = max({current, max_so_far * current, min_so_far * current});
            min_so_far = min({current, max_so_far * current, min_so_far * current});

            max_so_far = temp_max;

            // Update the result if the current max product is greater
            result = max(result, max_so_far);
        }

        return result;
    }
};

