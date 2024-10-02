class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
 
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        

        for (int i = 0; i < nums.size() - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = nums.size() - 1; 
            
            while (j < k) {
                int sum1 = nums[i] + nums[j] + nums[k];
                
                if (abs(sum1 - target) < abs(closestSum - target)) {
                    closestSum = sum1;
                }

                if (sum1 < target) {
                    j++; 
                } 
                else if (sum1 > target) {
                    k--;
                } 
                else {
                    return sum1;
                }
            }
        }
        return closestSum;
    }
};
