class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int , unordered_set<char>> row;
        unordered_map<int , unordered_set<char>> col;
        unordered_map<string,  unordered_set<char>> loc;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                string r = to_string(i/3);
                string c = to_string(j/3);

                string key = "";
                key = r + c;

                if (board[i][j] == '.'){
                    continue;
                }

                if(row[i].find(board[i][j]) != row[i].end() || col[j].find(board[i][j]) != col[j].end() || loc[key].find(board[i][j]) != loc[key].end()){
                    return false;
                }
                else{
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    loc[key].insert(board[i][j]);
                }
            }    
        }
        return true;
        
    }
};
