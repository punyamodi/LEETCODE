class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>cnt;
       vector<int>v;
        for(auto u:nums){
            cnt[u]++;
        }
        for(auto u:cnt){
            if(u.second==1){
                v.push_back(u.first);
            }
        }
        return v;
    }
};