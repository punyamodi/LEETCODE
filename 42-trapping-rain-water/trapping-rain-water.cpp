class Solution {
public:
    int trap(vector<int>& height) {
        int s=0, e=height.size()-1, vol=0,m=INT_MIN;
        while(e>s){
            if(height[e]>=height[s]){
                m=max(m,height[s]);
                vol+=m-height[s];
                s++;
            }
            else if(height[e]<height[s]){
                m=max(m,height[e]);
                vol+=m-height[e];
                e--;
            }
        }
        return vol;
    }
};
