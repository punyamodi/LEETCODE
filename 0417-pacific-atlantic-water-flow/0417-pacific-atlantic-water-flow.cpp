class Solution {
public:

    const string PACIFIC_OCEAN = "pacific";
    const string ATLANTIC_OCEAN = "atlantic";
    
    bool checkVisited(string ocean, pair<int, int> p){
        if(ocean == ATLANTIC_OCEAN)
            return p.second == 1;
        return p.first == 1;
    }

    void bfs(string ocean, vector<vector<int>>& heights, vector<vector<pair<int, int>>>& visited, queue<pair<int, int>>& q, vector<pair<int, int>>& directions, int n, int m){
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto it : directions){
                int x = row + it.first;
                int y = col + it.second;

                if(x<0 || x>=n || y<0 || y>=m || heights[x][y] < heights[row][col] || checkVisited(ocean, visited[x][y]))
                    continue;

                if(ocean == ATLANTIC_OCEAN)
                    visited[x][y].second = 1;
                else
                    visited[x][y].first = 1;

                q.push(make_pair(x, y));
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<pair<int, int>>> visited(n, vector<pair<int, int>> (m, {0, 0}));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            visited[n-1][i].second = 1;
            q.push({n-1, i});
        } 
        for(int i=0; i<n; i++){
            visited[i][m-1].second = 1;
            q.push({i, m-1});
        } 

        bfs(ATLANTIC_OCEAN ,heights, visited, q, directions, n, m);

        for(int i=0; i<n; i++){
            visited[i][0].first = 1;
            q.push({i, 0});
        } 
        for(int i=0; i<m; i++){
            visited[0][i].first = 1;
             q.push({0, i});
        }

        bfs(PACIFIC_OCEAN, heights, visited, q, directions, n, m);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pair<int, int> it = visited[i][j];
                if(it.first && it.second)
                    ans.push_back({i, j});
            }
        }

        return ans;

    }
};