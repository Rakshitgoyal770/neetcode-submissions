class Solution {
public:
    int rows, cols;

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visit,
             int prevHeight) {

        if (r < 0 || c < 0 || r >= rows || c >= cols)
            return;

        if (visit[r][c])
            return;

        if (heights[r][c] < prevHeight)
            return;

        visit[r][c] = true;

        dfs(r + 1, c, heights, visit, heights[r][c]);
        dfs(r - 1, c, heights, visit, heights[r][c]);
        dfs(r, c + 1, heights, visit, heights[r][c]);
        dfs(r, c - 1, heights, visit, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // Top and Bottom borders
        for (int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific, heights[0][c]);
            dfs(rows - 1, c, heights, atlantic, heights[rows - 1][c]);
        }

        // Left and Right borders
        for (int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific, heights[r][0]);
            dfs(r, cols - 1, heights, atlantic, heights[r][cols - 1]);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};