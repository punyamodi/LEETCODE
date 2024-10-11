class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=0,profit=0;
        bool holding=false;
        for(int i=0;i<n-1;i++){
            if(prices[i]>prices[i+1]  && holding==true){
                profit+=prices[i]-buy;
                holding=false;
            }
            else if(prices[i]<prices[i+1] && holding==false){
                buy=prices[i];
                holding=true;
            }
        }
        if(holding==true){
            profit+=prices[n-1]-buy;
        }
        return profit;
    }
};