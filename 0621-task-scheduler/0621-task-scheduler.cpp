class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        for(auto i : tasks) {
            m[i]++;
        }

        priority_queue<int>pq;

        for(auto i:m){
            pq.push(i.second);
        }

        int time = 0;
        while(!pq.empty()) {
            vector<int>temp;
            int a=0;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    int t=pq.top();
                    pq.pop();
                    t--;
                    temp.push_back(t);
                    a++;
                }
            }
            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                time+=a;
            }
            else{
                time+=n+1;
            }
        }
        return time;
    }
};
