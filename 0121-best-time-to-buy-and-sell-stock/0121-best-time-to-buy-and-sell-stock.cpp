class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices[0],p=0;
        for(int i=0;i<prices.size();i++){
            if(m>prices[i]){
                m=prices[i];
            }
            else{
                p=max(p,prices[i]-m);
            }
        }
        return p;
    }
};