class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        // first row and last row
        for (int i = 0; i < m; i++) {
            // start row
            if (!vis[0][i] && grid[0][i] == 1) {
                dfs(0, i, grid, vis);
            }
            // last row
            if (!vis[n - 1][i] && grid[n - 1][i] == 1) {
                dfs(n - 1, i, grid, vis);
            }
        }
        // first col and last col
        for (int i = 0; i < n; i++) {
            // start col
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis);
            }
            // end col
            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, vis);
            }
        }
        // entire matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};