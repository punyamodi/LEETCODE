class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.push_back(0);
        int curr_min=INT_MAX;
        int curr_max=INT_MIN;
        int profit = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<curr_max){
                profit += curr_max - curr_min;
                curr_min = INT_MAX;
                curr_max=INT_MIN;
            }
            curr_min = min(curr_min,prices[i]);
            curr_max = max(curr_max,prices[i]);
        }
        return profit;
    }
};

/*class Solution {
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
};*/