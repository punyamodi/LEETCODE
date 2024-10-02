class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> v;
        int c=0;
        for(auto it:nums){
            if(it==0){
                c++;
            }
            else{
                v.push_back(it);
            }
        }
        for(int i=0;i<c;i++){
            v.push_back(0);
        }
        nums=v;
    }
};