class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int m=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            if(m>arr[i+1]-arr[i]){
                m=arr[i+1]-arr[i];
            }
        }
        vector<vector<int>> a;
        for(int i=0;i<arr.size()-1;i++){
            if(m==arr[i+1]-arr[i]){
                a.push_back({arr[i],arr[i+1]});
            }
        }
        return a;
    }
};