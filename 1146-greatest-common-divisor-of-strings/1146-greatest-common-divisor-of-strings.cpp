class Solution {
public:
    // Helper function to calculate the GCD of two numbers
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    string gcdOfStrings(string str1, string str2) {
        // If str1 + str2 is not equal to str2 + str1, there is no common divisor
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Calculate the GCD of the lengths of str1 and str2
        int lenGCD = gcd(str1.size(), str2.size());
        
        // The result is the prefix of str1 (or str2) of length lenGCD
        return str1.substr(0, lenGCD);
    }
};
