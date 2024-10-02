class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,sum=0;
        for(auto it: gain){  
            sum+=it;   
            ans=max(sum,ans);
        }
        return ans;
    }
};