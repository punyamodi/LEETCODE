
class Solution {
public:
    int trap(vector<int>& height) {
        int low=0,high=height.size()-1,vol=0,m=INT_MIN;
        while(low<high){
            if(height[low]>=height[high]){
                m=max(m,height[high]);
                vol+=m-height[high];
                high--;
            }
            else if(height[low]<height[high]){
                m=max(m,height[low]);
                vol+=m-height[low];
                low++;
            }

        }
        return vol;
    }
};