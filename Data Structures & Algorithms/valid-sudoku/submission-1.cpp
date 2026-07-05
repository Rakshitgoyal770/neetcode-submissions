class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int , unordered_set<char>> row;
        unordered_map<int , unordered_set<char>> col;
        unordered_map<string,  unordered_set<char>> loc;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = board[i][j];
                string key = to_string(i/3) + to_string(j/3);

                if (board[i][j] == '.'){
                    continue;
                }

                if(row[i].find(ch) != row[i].end() || col[j].find(ch) != col[j].end() || loc[key].find(ch) != loc[key].end()){
                    return false;
                }

                else{
                    row[i].insert(ch);
                    col[j].insert(ch);
                    loc[key].insert(ch);
                }
            }    
        }
        return true;
        
    }
};
