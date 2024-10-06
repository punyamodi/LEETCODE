class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();

        vector<vector<int>> a(l1+1, vector<int>(l2+1, 0));

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {

                if (text1[i-1] == text2[j-1]) {
                    a[i][j] = 1 + a[i-1][j-1];
                } else {
                    a[i][j] = max(a[i-1][j], a[i][j-1]); 
                }
            }
        }

        return a[l1][l2];
    }
};
