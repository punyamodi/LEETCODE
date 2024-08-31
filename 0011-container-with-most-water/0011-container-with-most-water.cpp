class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1, vol = 0, m = 0;
        while (low < high) {
            int currentArea = min(height[high], height[low]) * (high - low);
            vol = max(vol, currentArea);
            if (height[low] > height[high]) {
                high--;
            }
            else{
                low++;
            }
        }
        return vol;
    }
};
