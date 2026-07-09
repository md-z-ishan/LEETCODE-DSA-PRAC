class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Push all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        int time = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();
            int rotten = 0;

            while (size--) {

                pair<int, int> curr = q.front();
                q.pop();

                int row = curr.first;
                int col = curr.second;

                for (int i = 0; i < 4; i++) {

                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rotten++;
                    }
                }
            }

            if (rotten > 0)
                time++;
        }

        if (fresh > 0)
            return -1;

        return time;
    }
};