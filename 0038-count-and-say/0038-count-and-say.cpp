class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string s = countAndSay(n - 1);
        string ans = "";  
        char temp = s[0]; 
        int count = 1;    

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == temp) {
                count++; 
            } else {
                ans += to_string(count) + temp; 
                temp = s[i];
                count = 1;  
            }
        }

        ans += to_string(count) + temp;

        return ans; 
    }
};