class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 'c' || grid[i][j] == '0') {
                    continue;
                } else {
                    islands++;
                    convert(grid, i, j); 
                }
            }
        }
        return islands;
    }

private:
    void convert(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0' || grid[r][c] == 'c') {
            return;
        }

        grid[r][c] = 'c';

        convert(grid, r + 1, c); 
        convert(grid, r - 1, c); 
        convert(grid, r, c + 1); 
        convert(grid, r, c - 1); 
    }
};
