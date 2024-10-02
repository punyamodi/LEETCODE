class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainderFreq(60, 0);  
        int ans = 0;

        for (int t : time) {
            int remainder = t % 60;
            int complement = (60 - remainder) % 60;  


            ans += remainderFreq[complement];
            remainderFreq[remainder]++;
        }

        return ans;
    }
};
