class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0,b=0;
        vector<int> ans;
        while(a<m && b<n){
            if(nums1[a]>=nums2[b]){
                ans.push_back(nums2[b]);
                b++;
            }
            else{
                ans.push_back(nums1[a]);
                a++;
            }
        }
        while(a<m){
            ans.push_back(nums1[a]);
            a++;
        }
        while(b<n){
            ans.push_back(nums2[b]);
            b++;
        }
        nums1=ans;
    }
};