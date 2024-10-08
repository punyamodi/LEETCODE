class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> a(n, vector<int>(n)); 
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                a[i][n - 1 - j] = matrix[j][i];
            }
        } 
        matrix=a;
    }
};

/*class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++){
                
                swap(matrix[i][j],matrix[j][i]);
                
            }
        }
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        } 
    }
};*/

