class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;

        // Push all gates
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc] : dir) {

                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nc < 0 || nr >= row || nc >= col)
                    continue;

                if(grid[nr][nc] != 2147483647)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
