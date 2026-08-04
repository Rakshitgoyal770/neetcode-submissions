class Solution {
public:
    int rows, cols;
    vector<vector<bool>> vac;

    void dfs(vector<vector<char>>& board, int i, int j) {

        if(i < 0 || j < 0 || i >= rows || j >= cols)
            return;

        if(!vac[i][j] || board[i][j] == 'X')
            return;

        vac[i][j] = false;

        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {

        rows = board.size();
        cols = board[0].size();

        vac.assign(rows, vector<bool>(cols, true));

        // left and right
        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O')
                dfs(board, i, 0);

            if(board[i][cols - 1] == 'O')
                dfs(board, i, cols - 1);
        }

        // top and bottom
        for(int j = 0; j < cols; j++) {
            if(board[0][j] == 'O')
                dfs(board, 0, j);

            if(board[rows - 1][j] == 'O')
                dfs(board, rows - 1, j);
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O' && vac[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};
