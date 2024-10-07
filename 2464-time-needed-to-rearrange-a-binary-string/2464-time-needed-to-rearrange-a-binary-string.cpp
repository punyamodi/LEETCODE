class Solution {
public:
    int secondsToRemoveOccurrences(string s) {

        int count=0,p=1;
        while(p==1){
            p=0;
            for(int i=0;i<s.size()-1;i++){
                if(s[i]=='0' && s[i+1]=='1'){
                    s[i]='1';
                    s[i+1]='0';
                    p=1;
                    i++;
                    
                }
            }
            if(p==1){
                count++;
            }
        }
        return count;
    }
};