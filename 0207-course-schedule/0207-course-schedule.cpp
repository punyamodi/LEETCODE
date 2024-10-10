class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        
        vector<int> state(numCourses, 0);
        
        function<bool(int)> dfs = [&](int course) {
            if (state[course] == 1) return false;
            if (state[course] == 2) return true;
            
            state[course] = 1;
            
            for (int neighbor : adj[course]) {
                if (!dfs(neighbor)) return false;
            }
            
            state[course] = 2;
            return true;
        };
        
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return false;
        }
        
        return true;
    }
};
