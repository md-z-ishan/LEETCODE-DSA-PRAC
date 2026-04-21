class Solution {
public:
    
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans = 1;
        
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int d = 0; d < 4; d++) {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, 1 + dfs(ni, nj, matrix, dp));
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, dfs(i, j, matrix, dp));
            }
        }
        
        return res;
    }
};