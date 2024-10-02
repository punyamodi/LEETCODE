class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size(),m=word2.size(),max;
        if(n>m){
            max=n;
        }
        else{
            max=m;
        }
        string str;
        for(int i=0;i<max;i++){
            if(i<n){
                str+=word1[i];
            }
            if(i<m){
                str+=word2[i];
            }
        }
        return str;
    }
};