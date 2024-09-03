class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        // Convert each character to its numeric value and sum the digits
        for(auto it: s){
            int num = it - 'a' + 1;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }
        }
        
        // Perform k iterations to sum the digits
        while(k > 1){
            int new_sum = 0;
            while(sum > 0){
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
            k--;
        }
        
        return sum;
    }
};
